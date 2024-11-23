#ifndef BARANG_H
#define BARANG_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct{
    Barang *buffer;
    int size;
    int capacity;
} ListBarang;

void create_list_barang(ListBarang *barangs);
int barang_count(ListBarang *barangs);
int barang_index(ListBarang *barangs, char *name);
void add_barang(ListBarang *barangs, char *name, int price);
void delete_barang(ListBarang *barangs, char *name);
boolean is_barang_exist(ListBarang *barangs, char *name);

#endif