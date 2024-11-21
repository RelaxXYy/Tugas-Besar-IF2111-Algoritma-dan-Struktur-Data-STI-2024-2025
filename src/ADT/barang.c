#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

Barang barangs[MAX_BARANG];

int barang_count(Barang *barangs) {
    int i = 0;
    while (barangs[i].name[0] != '\0') {
        i++;
    }
    return i;
}

int barang_index(Barang *barangs, const char *name) {
    int i = 0;
    while (barangs[i].name[0] != '\0') {
        if (is_same_string(barangs[i].name, name) == true) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_barang(Barang *barangs, const char *name, int price) {
    int i = barang_count(barangs);
    copy_string(barangs[i].name, name);
    barangs[i].price = price;
}

boolean is_barang_exist(Barang *barangs, const char *name) {
    return barang_index(barangs, name) != -1;
}