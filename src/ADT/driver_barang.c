#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"
#include "../include/barang.h"

int main() {
    ListBarang barangs;
    create_list_barang(&barangs);

    add_barang(&barangs, "Laptop", 1500);
    add_barang(&barangs, "Mouse", 50);
    add_barang(&barangs, "Keyboard", 100);
    

    printf("Barang count: %d\n", barang_count(&barangs));
    printf("Is Laptop exist: %d\n", is_barang_exist(&barangs, "Laptop"));
    printf("Index of Mouse: %d\n", barang_index(&barangs, "Mouse"));
    printf("Is Keyboard exist: %d\n", is_barang_exist(&barangs, "Keyboard"));
    printf("Index of Keyboard: %d\n", barang_index(&barangs, "Keyboard"));

    // Test deleting a barang
    delete_barang(&barangs, "Mouse");
    printf("Barang count after deleting Mouse: %d\n", barang_count(&barangs));
    printf("Is Mouse exist after deletion: %d\n", is_barang_exist(&barangs, "Mouse"));

    // Free the allocated memory
    free(barangs.buffer);

    return 0;
}