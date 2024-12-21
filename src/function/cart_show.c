#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "cart_show.h"

void cart_show(){
    if (is_cart_empty(&current_user.cart)){
        printf("Keranjang belanja kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu.\n");
    printf("\nKuantitas\tNama\tTotal\t\n");
    for (int i = 0; i < current_user.cart.count; i++){
        printf("%d\t\t%s\t%d\t\t\n", current_user.cart.CartElement[i].amount, current_user.cart.CartElement[i].name, harga_barang(&barangs, current_user.cart.CartElement[i].name) * current_user.cart.CartElement[i].amount);
    }
}