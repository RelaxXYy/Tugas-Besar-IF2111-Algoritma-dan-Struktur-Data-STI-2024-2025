#include <stdio.h>
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

void add_cart_to_history() {
    for (int i = 0; i < current_user.cart.count; i++) {
        add_cart_to_history(&history_temp, barangs.buffer[index_barang(current_user.cartElement[i].name)], current_user.cart.CartElement[i].amount);
    }
}

void totalharga() {
    int tot = 0;
    for (int i = 0; i < current_user.cart.count; i++) {
        int tot += harga_barang(&barangs, current_user.cart.CartElement[i].name) * current_user.cart.CartElement[i].amount;
    }
}

void cartpay(char *response) {
    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("\nKuantitas\tNama\tTotal\t\n");
    for (int i = 0; i < current_user.cart.count; i++){
        printf("%d\t\t%s\t%d\t\t\n", current_user.cart.CartElement[i].amount, current_user.cart.CartElement[i].name, harga_barang(&barangs, current_user.cart.CartElement[i].name) * current_user.cart.CartElement[i].amount);
    }

    if (is_same_string(response, "YA")) {
        if (current_user.money >= totalharga()) {
            current_user.money - totalharga();
            current_user.cart.count = 0;
        
            add_cart_to_history();

            printf("Selamat kamu telah membeli barang yang ada di dalam keranjang!\n");
        }

        else if (is_cart_empty) {
            printf("Keranjang kosong.")
        }

        else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", current_user.money)
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
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalharga());

    get_line();
    copy_string(word_to_string(current_word), response);
    upper_string(response);
    execute_command();

}