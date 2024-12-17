#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void store_remove(char *name) {

    if (!is_barang_exist(&barangs, name)) {
        printf("Toko tidak menjual \"%s\".\n", name);
        return;
    }
    else{
        delete_barang(&barangs, name);
        printf("%s berhasil dihapus dari toko.\n", name);
    }

}

void store_remove_main() {
    char input[100];

    if(barang_count(&barangs) == 0) {
        printf("Tidak ada barang di toko.\n");
        execute_command();
    }
    printf("Nama barang yang akan dihapus: ");
    get_line();
    copy_string(word_to_string(current_word), input);
    store_remove(input);
    execute_command();
    
}