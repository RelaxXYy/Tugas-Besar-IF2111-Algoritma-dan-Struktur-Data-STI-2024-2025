#include "cart.h"

void create_cart(Cart *cart) {
    cart->count = 0;
}

boolean is_cart_empty(Cart *cart) {
    return cart->count == 0;
}

boolean is_cart_full(Cart *cart) {
    return cart->count == MAX_LIST;
}

int cart_value(Cart *cart, char *name) {
    int index = 0;
    while (index < cart->count && index < MAX_LIST && cart->CartElement[index].name != name) index++;
    if (index < cart->count) return cart->CartElement[index].amount;
    else return 0;
}

void insert_cart(Cart *cart, char *name, int amount) {
    if (cart_value(cart, name) == 0 && !is_cart_full(cart) && is_barang_exist(&barangs, name)) {
        copy_string(name, cart->CartElement[cart->count].name);
        cart->CartElement[cart->count].amount = amount;
        cart->count++;
    }
}

void delete_cart(Cart *cart, char *name) {
    int index = 0;
    while (index < cart->count && index < MAX_LIST && cart->CartElement[index].name != name) index++;
    if (index < cart->count) {
        for (int i = index; i < cart->count - 1; i++) {
            cart->CartElement[i] = cart->CartElement[i + 1];
        }
        cart->count--;
    }
}

boolean is_exist_in_cart(Cart *cart, char *name) {
    return (cart_value(cart, name) > 0);
}

