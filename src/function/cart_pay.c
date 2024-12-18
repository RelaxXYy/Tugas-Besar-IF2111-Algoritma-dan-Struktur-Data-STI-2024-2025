#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

// NOTES
// Value = kuantitas barang di keranjang                (line 38)
// Key = nama barang                                    (line 38)
// Total = harga barang, total blm tau disimpen di mana (line 38)
// add_keranjang_to_riwayat ganti aja dan
// sumHarga = total harga barang yang harus dibayar, krn blm tau Total disimpen di mana, gw blm bisa bikin

void add_keranjang_to_riwayat(Map keranjang, Stack *riwayat_pembelian) {
    for (int i = 0; i < keranjang.Count; i++) {
        if (riwayat_pembelian->IndexTop < MaxEl - 1) {
            riwayat_pembelian->IndexTop++;
            riwayat_pembelian->Elements[riwayat_pembelian->IndexTop] = keranjang.Elements[i].Key;
        }
    }
}

void cartpay(char *response) {

    int sumValue;

    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("Kuantitas   Nama    Total\n");   

    for (int i = 0; i < keranjang.Count; i++) {

        printf("%s  %d  %s\n", keranjang.Elements[i].Value, keranjang.Elements[i].Key, keranjang.Elements.Total);

    }

    if (is_same_string(response, "YA")) {
        if (current_user.money >= harga) {
            current_user.money - harga;
            keranjang.Count = 0;
        
            add_keranjang_to_riwayat();

            printf("Selamat kamu telah membeli barang yang ada di dalam keranjang!\n");
        }
        else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", current_user.money);
        }
    }

    else if (is_same_string(response, "TIDAK")) {
        printf("Kembali ke menu utama\n");
    }

    else {
        printf("Input tidak valid\n");
    }

}

void cartpay_main() {

    cartpay();

    char response[100];

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", sumHarga);

    get_line();
    copy_string(word_to_string(current_word), response);
    upper_string(response);
    execute_command();

}