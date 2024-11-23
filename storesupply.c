#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

extern Barang barangs[MAX_BARANG];
extern Queue queue;
extern int barang_count;

void store_supply(char *repsonse, int price) {

    if (is_queue_empty(&queue)) {
        // Mengecek jika queue kosong
        printf("Antrian permintaan barang kosong.\n");
        return;
    }

    dequeue(&queue, queue.head);

    if (is_same_string(response, "Terima")) {
        if (price > 0) {
            // Menambahkan barang dalam antrian ke toko
            barangs[barang_count - 1].price = price;
            barangs[barang_count - 1].name = queue.buffer[queue.head];
            barang_count++;

            printf("%s dengan harga %d telah ditambahkan ke toko.\n", queue.buffer[queue.head], price);
        } 
        
        else {
            printf("%s gagal ditambahkan ke toko karena harga tidak valid.\n");
            enqueue(&queue, queue.head)
            return;
        }
    } 
    
    else if (is_same_string(response, "Tunda")) {
        // Mengembalikan barang ke antrian paling belakang    
        enqueue(&queue, queue.tail);
        printf("%s dikembalikan ke antrian.\n", queue.buffer[queue.tail]);
        price = 0;
    } 
    
    else if (is_same_string(response, "Tolak")) {
        printf("%s dihapuskan dari antrian.\n", queue.buffer[queue.head]);
        price = 0;
    } 
    
    else if (is_same_string(response, "Purry")) {
        // Mengembalikan barang ke antrian di posisi semula     
        enqueue(&queue, queue.head);
        return;
    }
    
    else {
        printf("Input tidak valid. %s dikembalikan ke antrian.\n", queue[queue.head]);
        enqueue(&queue, queue.head);
        price = 0;
    }
}

void store_supply_main() {

    char response[100];
    int price;

    printf(">> STORE SUPPLY\n");

    while (!is_queue_empty(&queue)) {
        printf("Apakah kamu ingin menambahkan barang %s: \n", queue.buffer[queue.head]);
        scanf("%s", response);

        if (is_same_string(response, "Terima")) {
            printf("Harga barang: ");
            scanf("%d", &price);
        } 
        
        else if (is_same_string(response, "EXIT")) {
            printf("Program selesai.\n");
            break;
        }       

        else {
            // Jika tidak menerima informasi dari harga barang yang tidak ditambahkan, maka diasumsikan harga yang belum diketahu bernilai 0
            price = 0;
        }

        store_supply(response, price);
    }
}