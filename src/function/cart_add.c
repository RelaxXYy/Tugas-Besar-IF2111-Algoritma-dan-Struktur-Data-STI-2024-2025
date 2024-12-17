#include <stdio.h>
#include <stdlib.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

// key : namabarang , value : kuantitas

int is_same_string(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; 
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0'); 
}

void copy_string(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

int store_item_exists(Store *toko, char *namabarang) {
    for (int i = 0; i < toko->Count; i++) {
        if (is_same_string(toko->Items[i], namabarang)) {
            return 1; 
        }
    }
    return 0; 
}

void cart_add(Map *keranjang, Store *toko, char *namabarang, int kuantitas) {
    if (kuantitas <= 0) {
        printf("Kuantitas tidak valid!\n");
        return;
    }

    if (!store_item_exists(toko, namabarang)) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    int index = -1;
    for (int i = 0; i < keranjang->Count; i++) {
        if (is_same_string(keranjang->Elements[i].Key, namabarang)) {
            index = i;
            break;
        }
    }

    if (index == -1) { 
        if (keranjang->Count < MaxEl) {
            copy_string(keranjang->Elements[keranjang->Count].Key, namabarang);
            keranjang->Elements[keranjang->Count].Value = kuantitas;
            keranjang->Count++;
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, namabarang);
        } else {
            printf("Keranjang penuh!\n");
        }
    } else { // barang sudah ada di keranjang, hanya kuantitas yang ditambah
        keranjang->Elements[index].Value += kuantitas;
        printf("Berhasil menambahkan %d %s ke keranjang belanja (UPDATE)!\n", kuantitas, namabarang);
    }
    printf("// Kembali ke menu utama\n");
}
