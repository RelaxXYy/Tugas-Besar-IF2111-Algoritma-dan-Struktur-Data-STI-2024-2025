#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "cart_pay.h"

void add_cart_to_history() {
    History temp_history = current_user.riwayat_pembelian;
    for (int i = 0; i < current_user.cart.count; i++) {
        HistoryElement temp_history_element;
        add_cart_to_history(&temp_history, barangs.buffer[barang_index(&barangs,current_user.cart.CartElement[i].name)], current_user.cart.CartElement[i].amount);
    }
}

int totalharga() {
    int tot = 0;
    for (int i = 0; i < current_user.cart.count; i++) {
        int tot = tot + harga_barang(&barangs, current_user.cart.CartElement[i].name) * current_user.cart.CartElement[i].amount;
    }
}

void cart_pay(char *response) {
    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("\nKuantitas\tNama\tTotal\t\n");
    for (int i = 0; i < current_user.cart.count; i++){
        printf("%d\t\t%s\t%d\t\t\n", current_user.cart.CartElement[i].amount, current_user.cart.CartElement[i].name, harga_barang(&barangs, current_user.cart.CartElement[i].name) * current_user.cart.CartElement[i].amount);
    }

    if (is_same_string(response, "YA")) {
        if (current_user.money >= totalharga()) {
            current_user.money = current_user.money - totalharga();
            current_user.cart.count = 0;
        
            add_cart_to_history();

            printf("Selamat kamu telah membeli barang yang ada di dalam keranjang!\n");
        }

        else if (is_cart_empty) {
            printf("Keranjang kosong.");
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

void cart_pay_main() {
    char response[100];
    cart_pay(response);
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalharga());

    get_line();
    copy_string(word_to_string(current_word), response);
    upper_string(response);
    return;

}