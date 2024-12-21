#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "store_request.h"

void store_request(char *name) {

    // apakah barang sudah ada di toko atau belum
    if (is_barang_exist(&barangs, name)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // apakah barang sudah ada di dalam antrian
    if(is_barang_exist_queue(&qbarangs, name)) {
        printf("Barang sudah ada di dalam antrian!\n");
        return;
    }

    // tambahkan barang ke antrian
    if (qbarangs.count < MAX_QUEUE) {
        enqueue_barang(&qbarangs, name);
        printf("Barang berhasil diminta.\n");
        return;
    } else {
        printf("Antrian penuh.\n");
        return;
    }
}

void store_request_main() {
    char input[100];

    printf("Nama barang yang diminta: ");
    get_line();
    copy_string(word_to_string(current_word), input);
    store_request(input);
    return;

}