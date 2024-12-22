#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "wishlist_swap.h"

void wishlist_swap(char *pos_barang1, char *pos_barang2) {
    int pos_barang1_int, pos_barang2_int;
    if (is_wishlist_empty(&current_user.wishlist)) {
        printf("Wishlist kosong!\n");
        return;
    }
    
    if(!is_digit(pos_barang1) || !is_digit(pos_barang2)){
        printf("Input harus berupa angka!\n");
        return;
    }

    string_to_int(pos_barang1, &pos_barang1_int);
    string_to_int(pos_barang2, &pos_barang2_int);

    Address P1 = search_wishlist(&current_user.wishlist, pos_barang1_int);
    Address P2 = search_wishlist(&current_user.wishlist, pos_barang2_int);

    if (P1 == NULL || P2 == NULL) {
        printf("Salah satu atau kedua barang tidak ada di wishlist!\n");
        return;
    }

    swap_wishlist(&current_user.wishlist, P1->Nama, P2->Nama);
    printf("Barang %s dan %s berhasil ditukar posisinya di wishlist!\n", P1->Nama, P2->Nama);
}