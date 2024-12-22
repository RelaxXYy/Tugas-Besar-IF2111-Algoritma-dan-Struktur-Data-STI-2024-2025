#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "wishlist_add.h"

void wishlist_add(char *nama_barang) {

    if (!is_barang_exist(&barangs, nama_barang)) { 
        printf("Tidak ada barang dengan nama %s di toko!\n", nama_barang);
        return;
    }

    if (search_wishlist_name(&current_user.wishlist,nama_barang ) != NULL) {
        printf("%s sudah ada di wishlist!\n", nama_barang);
        return;
    }

    insert_wishlist(&current_user.wishlist, nama_barang);
    printf("%s berhasil ditambahkan ke wishlist!\n", nama_barang);
}

void wishlist_add_main() {
    char nama_barang[MAX_LEN];
    printf("Masukkan nama barang yang ingin ditambahkan ke wishlist: ");
    get_line();
    copy_string(word_to_string(current_word), nama_barang);
    wishlist_add(nama_barang);
}
