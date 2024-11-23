#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void create_list_barang(ListBarang *barangs) {
    (*barangs).buffer = (Barang*) malloc(INIT_BARANG * sizeof(Barang));
    (*barangs).size = 0;
    (*barangs).capacity = INIT_BARANG;
}

void resize_list_barang(ListBarang *barangs) {
    int new_capacity = (*barangs).capacity * 2;
    Barang *new_buffer = (Barang*) malloc(new_capacity * sizeof(Barang));
    for (int i = 0; i < (*barangs).size; i++) {
        new_buffer[i] = (*barangs).buffer[i];
    }
    free((*barangs).buffer);
    (*barangs).buffer = new_buffer;
    (*barangs).capacity = new_capacity;
}

int barang_count(ListBarang *barangs) {
    return (*barangs).size;
}

int barang_index(ListBarang *barangs, char *name) {
    int i = 0;
    while ((*barangs).buffer[i].name[0] != '\0') {
        if (is_same_string((*barangs).buffer[i].name, name) == true) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_barang(ListBarang *barangs, char *name, int price) {
    int i = barang_count(barangs);
    if (i == (*barangs).capacity) {
        int new_capacity = (*barangs).capacity * 2;
        Barang *new_buffer = (Barang*) malloc(new_capacity * sizeof(Barang));
        for (int i = 0; i < (*barangs).size; i++) {
            new_buffer[i] = (*barangs).buffer[i];
        }
        free((*barangs).buffer);
        (*barangs).buffer = new_buffer;
        (*barangs).capacity = new_capacity;
        }
    copy_string(name, (*barangs).buffer[i].name);
    (*barangs).buffer[i].price = price;
    (*barangs).size++;
}

void delete_barang(ListBarang *barangs, char *name) {
    int index = barang_index(barangs, name);
    if (index != -1) {
        for (int i = index; i < (*barangs).size - 1; i++) {
            copy_string((*barangs).buffer[i + 1].name, (*barangs).buffer[i].name);
            (*barangs).buffer[i].price = (*barangs).buffer[i + 1].price;
        }
        (*barangs).size--;
    }
}

boolean is_barang_exist(ListBarang *barangs, char *name) {
    return barang_index(barangs, name) != -1;
}