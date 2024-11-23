#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

extern Barang barangs[MAX_BARANG];
extern int barang_count;

// Asumsi toko pasti terisi
void store_remove(char *name) {

    // Mengecek jika barang tidak ada dalam toko
    if (!is_barang_exist(barangs, name)) {
        printf("Toko tidak menjual %s.\n", name);
        return;
    }

    // Remove barang dari toko
    int barangindex = 0;
    while (name != barangs[i].name) {
        barangindex++;
    }

    for (int i = barangindex; i < barang_count - 1; i++) {
        barangs[i] = barangs[i+1];
    }

    barang_count--;

}

void store_request_main() {
    char input[100];
    printf(">> STORE REMOVE\n");

    while (1) { 
        printf("Nama barang yang akan dihapus: ");
        scanf("%s", input);

        if (is_same_string(input, "EXIT")) {
            printf("Program selesai.\n");
            break;
        }

        store_remove(input);
    }
}