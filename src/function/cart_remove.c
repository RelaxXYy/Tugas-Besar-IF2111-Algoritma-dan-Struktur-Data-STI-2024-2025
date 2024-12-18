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

void cart_remove(Map *keranjang, char *namabarang, int kuantitas) {
    if (kuantitas <= 0) {
        printf("Kuantitas tidak valid!\n");
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
        printf("Barang tidak ada di keranjang belanja!\n");
        return;
    }

    if (keranjang->Elements[index].Value < kuantitas) {
        printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", keranjang->Elements[index].Value, namabarang);
        return;
    }

    keranjang->Elements[index].Value -= kuantitas;
    if (keranjang->Elements[index].Value == 0) { 
        for (int i = index; i < keranjang->Count - 1; i++) {
            keranjang->Elements[i] = keranjang->Elements[i + 1]; 
        }
        keranjang->Count--;
        printf("Berhasil menghapus %s dari keranjang belanja!\n", namabarang);
    } else {
        printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, namabarang);
    }
    printf("// Kembali ke menu utama\n");
}
