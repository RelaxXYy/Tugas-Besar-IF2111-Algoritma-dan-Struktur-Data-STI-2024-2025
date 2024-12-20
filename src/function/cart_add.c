#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

void cart_add(char *nama_barang, int kuantitas) {

    if (barang_index(&barangs, nama_barang) == -1) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    if (kuantitas <= 0) {
        printf("Kuantitas tidak valid!\n");
        return;
    }

    if (!is_barang_exist(&barangs, nama_barang)) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    if (is_exist_in_cart(&current_user.cart, &barangs.buffer[barang_index(&barangs, nama_barang)])) {
        int temp_value;
        temp_value = cart_value(&current_user.cart, &barangs.buffer[barang_index(&barangs, nama_barang)]);
        delete_cart(&current_user.cart, &barangs.buffer[barang_index(&barangs, nama_barang)]);
        insert_cart(&current_user.cart, &barangs.buffer[barang_index(&barangs, nama_barang)], temp_value + kuantitas);
        printf("Berhasil menambahkan %d %s ke keranjang belanja (UPDATE)!\n", kuantitas, nama_barang);
    }
    else {
        insert_cart(&current_user.cart, &barangs.buffer[barang_index(&barangs, nama_barang)], kuantitas);
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, nama_barang);
    }
}