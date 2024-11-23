#ifndef BARANG_H
#define BARANG_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

int barang_count(Barang *barangs);
int barang_index(Barang *barangs, char *name);
void add_barang(Barang *barangs, char *name, int price);
boolean is_barang_exist(Barang *barangs, char *name);

#endif