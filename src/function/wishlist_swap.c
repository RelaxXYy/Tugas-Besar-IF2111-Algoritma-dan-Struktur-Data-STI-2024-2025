#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

void wishlist_swap(char *nama_barang1, char *nama_barang2) {
    if (is_wishlist_empty(&current_user.wishlist)) {
        printf("Wishlist kosong!\n");
        return;
    }

    Address P1 = search_wishlist(&current_user.wishlist, nama_barang1);
    Address P2 = search_wishlist(&current_user.wishlist, nama_barang2);

    if (P1 == NULL || P2 == NULL) {
        printf("Salah satu atau kedua barang tidak ada di wishlist!\n");
        return;
    }

    swap_wishlist(&current_user.wishlist, P1->Nama, P2->Nama);
    printf("Barang %s dan %s berhasil ditukar posisinya di wishlist!\n", nama_barang1, nama_barang2);
}