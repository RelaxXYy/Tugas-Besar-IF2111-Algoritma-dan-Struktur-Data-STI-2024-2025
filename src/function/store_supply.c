#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void store_supply(char *response, int price) {

    if (is_queue_barang_empty(&qbarangs)) {
        printf("Antrian permintaan barang kosong.\n");
        return;
    }


    if (is_same_string(response, "TERIMA")) {
        char name[MAX_LEN];
        dequeue_barang(&qbarangs, name);
        add_barang(&barangs, name, price);
        printf("%s dengan harga %d telah ditambahkan ke toko.\n", name, price);
    } 
    
    else if (is_same_string(response, "TUNDA")) {   
        char name[MAX_LEN];
        dequeue_barang(&qbarangs, name);
        enqueue_barang(&qbarangs, name);
        printf("%s dikembalikan ke antrian.\n", name);
    } 
    
    else if (is_same_string(response, "TOLAK")) {
        char name[MAX_LEN];
        dequeue_barang(&qbarangs, name);
        printf("%s dihapuskan dari antrian.\n", name);
    } 

    else if (is_same_string(response, "PURRY")) {
        return;
    }
    
    else {
        printf("Input tidak valid, silakan ulangi (Terima/Tunda/Tolak/Purry): ");
        get_line();
        copy_string(word_to_string(current_word), response);
        store_supply(response, price);
    }
}

void store_supply_main() {

    char response[100];

    if(is_queue_barang_empty(&qbarangs)) {
        printf("Tidak ada barang pada antrian.\n");
        execute_command();
    }
    printf("Apakah kamu ingin menambahkan barang %s? (Terima/Tunda/Tolak/Purry) : ", qbarangs.name[qbarangs.head]);
    get_line();
    copy_string(word_to_string(current_word), response);
    upper_string(response);
    int price = 0;
    if (is_same_string(response, "TERIMA")) {
        printf("Harga barang: ");
        start(NULL);
        while (get_current_char() != '\n' && !is_eop()) {
            price = price * 10 + (get_current_char() - '0');
            adv();
        }
        while (price <= 0) {
            printf("Harga tidak valid. Silakan masukkan harga barang: ");
            start(NULL);
            while (get_current_char() != '\n' && !is_eop()) {
                price = price * 10 + (get_current_char() - '0');
                adv();
            }
        }
    } 
    store_supply(response, price);
    execute_command();
}