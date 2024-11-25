#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

int main() {
    ListBarang barangs;
    QueueBarang qbarangs;

    create_list_barang(&barangs);
    create_queue_barang(&qbarangs);

    add_barang(&barangs, "Apel", 5000);
    add_barang(&barangs, "Pisang", 3000);
    add_barang(&barangs, "Mangga", 7000);

    print_list_barang(&barangs);

    delete_barang(&barangs, "Pisang");

    printf("\nSetelah menghapus Pisang:\n");
    print_list_barang(&barangs);

    enqueue_barang(&qbarangs, "Apel");
    enqueue_barang(&qbarangs, "Mangga");
    enqueue_barang(&qbarangs, "Pisang");

    printf("\nQueue setelah enqueue:\n");
    print_queue_barang(&qbarangs);

    char name[MAX_LEN];
    dequeue_barang(&qbarangs, name);
    printf("\nBarang yang di-dequeue: %s\n", name);

    printf("\nQueue setelah dequeue:\n");
    print_queue_barang(&qbarangs);

    if (is_barang_exist_queue(&qbarangs, "Mangga")) {
        printf("\nMangga ada di dalam queue.\n");
    } else {
        printf("\nMangga tidak ada di dalam queue.\n");
    }

    free(barangs.buffer);

    return 0;
}