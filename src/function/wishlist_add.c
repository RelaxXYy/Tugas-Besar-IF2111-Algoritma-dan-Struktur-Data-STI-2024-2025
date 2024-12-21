#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "wishlist_add.h"

void wishlist_add(char *nama_barang, int quantity) {
    if (!is_barang_exist(&barangs, nama_barang)) { 
        printf("Tidak ada barang dengan nama %s di toko!\n", nama_barang);
        return;
    }

    if (search_wishlist(&current_user.wishlist, nama_barang) != NULL) {
        printf("%s sudah ada di wishlist!\n", nama_barang);
        return;
    }

    insert_wishlist(&current_user.wishlist, nama_barang);
    printf("%s berhasil ditambahkan ke wishlist!\n", nama_barang);
}
