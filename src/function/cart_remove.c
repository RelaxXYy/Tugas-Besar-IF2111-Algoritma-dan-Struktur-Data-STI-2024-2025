#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "cart_remove.h"

void cart_remove(char *nama_barang, int kuantitas) {

    if (barang_index(&barangs, nama_barang) == -1) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    if (kuantitas <=0 || kuantitas < cart_value(&current_user.cart, barangs.buffer[barang_index(&barangs, nama_barang)].name)) {
        printf("Kuantitas tidak valid!\n");
        return;
    }

    if (!is_exist_in_cart(&current_user.cart, barangs.buffer[barang_index(&barangs, nama_barang)].name)) {
        printf("Barang tidak ada di keranjang belanja!\n");
        return;
    }

    int temp_value;
    temp_value = cart_value(&current_user.cart, barangs.buffer[barang_index(&barangs, nama_barang)].name);
    delete_cart(&current_user.cart, barangs.buffer[barang_index(&barangs, nama_barang)].name);
    temp_value -= kuantitas;
    if (temp_value > 0) {
        insert_cart(&current_user.cart, barangs.buffer[barang_index(&barangs, nama_barang)].name, temp_value);
        printf("Berhasil mengurangi %d %s dari keranjang belanja (UPDATE)!\n", kuantitas, nama_barang);
    } else {
        printf("Berhasil menghapus %s dari keranjang belanja!\n", nama_barang);
    }
}
