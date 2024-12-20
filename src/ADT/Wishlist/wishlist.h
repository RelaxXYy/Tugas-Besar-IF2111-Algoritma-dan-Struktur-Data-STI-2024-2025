#ifndef WISHLIST_H
#define WISHLIST_H

#include "../all_ADT_headers.h"
#include "../../config.h"
#include "../../boolean.h"

typedef struct PointerWishlistElement *Address;

typedef struct PointerWishlistElement {
    char Nama[MAX_LEN];
    Address Next;
} WishlistElement;

typedef struct {
    Address First;
} Wishlist;

void create_wishlist(Wishlist *wishlist);
boolean is_wishlist_empty(Wishlist *wishlist);
Address alokasi (char *name);
void dealokasi (Address *P);
Address search_wishlist(Wishlist *wishlist, char *name);
void insert_wishlist(Wishlist *wishlist, char *name);
void delete_wishlist(Wishlist *wishlist, char *name);
void swap_wishlist(Wishlist *wishlist, char *name1, char *name2);
int count_wishlist(Wishlist *wishlist);
void print_wishlist(Wishlist *wishlist);

#endif