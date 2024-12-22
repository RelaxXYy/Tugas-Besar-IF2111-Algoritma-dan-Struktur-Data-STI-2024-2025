#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

int main() {
    ListBarang listBarang;
    create_list_barang(&listBarang);

    add_barang(&listBarang, "AWM", 10000);
    add_barang(&listBarang, "KAR49", 20000);
    add_barang(&listBarang, "M4", 15000);

    printf("Di dalam list ada %d barang.\n", barang_count(&listBarang));

    print_list_barang(&listBarang);

    if (is_barang_exist(&listBarang, "AWM")) {
        printf("AWM ditemukan seharga %d\n", harga_barang(&listBarang, "AWM"));
    } else {
        printf("AWM tidak ditemukan.\n");
    }

    delete_barang(&listBarang, "KAR49");
    printf("KAR49 telah dihapus.\n");

    print_list_barang(&listBarang);

    QueueBarang queueBarang;
    create_queue_barang(&queueBarang);

    enqueue_barang(&queueBarang, "AWM");
    enqueue_barang(&queueBarang, "M4");

    printf("Queue Barang setelah enqueue:\n");
    print_queue_barang(&queueBarang);

    char dequeuedItem[MAX_LEN];
    dequeue_barang(&queueBarang, dequeuedItem);
    printf("Barang yang di-dequeue: %s\n", dequeuedItem);

    char frontItem[MAX_LEN];
    front_barang(&queueBarang, frontItem);
    printf("Barang di depan queue: %s\n", frontItem);

    return 0;
}