#include <stdio.h>
#include <stdbool.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

bool is_same_string(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void cartadd(Map *keranjang, Store *toko, char *namabarang, int kuantitas) {
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
            int j = 0;
            while (namabarang[j] != '\0') { 
                keranjang->Elements[keranjang->Count].Key[j] = namabarang[j];
                j++;
            }
            keranjang->Elements[keranjang->Count].Key[j] = '\0'; 

            keranjang->Elements[keranjang->Count].Value = kuantitas;
            keranjang->Count++;
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, namabarang);
        } else {
            printf("Keranjang penuh :(\n");
        }
    } else { 
        keranjang->Elements[index].Value += kuantitas;
        printf("Berhasil menambahkan %d %s ke keranjang belanja (UPDATE)!\n", kuantitas, namabarang);
    }
    printf("Kembali ke menu utama\n");
}
