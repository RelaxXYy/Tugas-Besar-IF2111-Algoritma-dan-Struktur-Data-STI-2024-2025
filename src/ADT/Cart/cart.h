#ifndef CART_H
#define CART_H

#include "../Barang/barang.h"
#include "../../config.h"
#include "../../boolean.h"

typedef struct {
    char name[MAX_LEN];
    int amount;
} CartElement;

typedef struct {
    CartElement CartElement[MAX_LIST];
    int count;
} Cart;

void create_cart(Cart *cart);
boolean is_cart_empty(Cart *cart);
boolean is_cart_full(Cart *cart);
int cart_value(Cart *cart, char *name);
void insert_cart(Cart *cart, char *name, int amount);
void delete_cart(Cart *cart, char *name);
boolean is_exist_in_cart(Cart *cart, char *name);

#endif