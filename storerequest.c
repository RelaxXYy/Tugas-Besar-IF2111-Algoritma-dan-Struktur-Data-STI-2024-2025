#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

extern Barang barangs[MAX_BARANG];
extern Queue queue;

void store_request(char *name) {
    // apakah barang sudah ada di toko atau belum
    if (is_barang_exist(barangs, name)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // apakah barang sudah ada di dalam antrian
    int queueindex = queue.head;
    while (queueindex != queue.tail) {
        if (is_same_string(queue.buffer[queueindex], name)) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
            return;
        }
        queueindex = (queueindex + 1) % MAX_QUEUE;
    }

    // tambahkan barang ke antrian
    if (!is_queue_full(&queue)) {
        enqueue(&queue, name);
        printf("Barang berhasil diminta.\n");
    } else {
        printf("Antrian penuh.\n");
    }
}

void store_request_main() {
    create_queue(&queue); 
    char input[100];
    printf(">> STORE REQUEST\n");

    while (1) { 
        printf("Nama barang yang diminta: ");
        scanf("%s", input);

        if (is_same_string(input, "EXIT")) {
            printf("Program selesai.\n");
            break;
        }
        store_request(input);
    }
}
