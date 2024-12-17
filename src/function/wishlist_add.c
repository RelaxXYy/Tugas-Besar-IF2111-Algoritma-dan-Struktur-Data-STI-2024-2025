#include <stdio.h>
#include <stdlib.h>
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

void copystring(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

bool store_item_exists(Store *toko, char *namabarang) {
    for (int i = 0; i < toko->Count; i++) {
        if (is_same_string(toko->Items[i], namabarang)) {
            return true;
        }
    }
    return false;
}

bool wishlist_item_exists(LinkedListChar *wishlist, char *namabarang) {
    Address P = wishlist->First;
    while (P != NULL) {
        if (is_same_string(P->Nama, namabarang)) {
            return true;
        }
        P = P->Next;
    }
    return false;
}

void wishlistadd(LinkedListChar *wishlist, Store *toko, char *namabarang) {
    if (!store_item_exists(toko, namabarang)) {
        printf("Tidak ada barang dengan nama %s di toko!\n", namabarang);
        return;
    }

    if (wishlist_item_exists(wishlist, namabarang)) {
        printf("%s sudah ada di wishlist!\n", namabarang);
        return;
    }

    // add barang ke wishlist
    Address newNode = (Address) malloc(sizeof(ElementsChar));
    if (newNode != NULL) {
        copystring(newNode->Nama, namabarang); 
        newNode->Next = NULL;

        if (wishlist->First == NULL) { 
            wishlist->First = newNode;
        } else { 
            Address P = wishlist->First;
            while (P->Next != NULL) {
                P = P->Next;
            }
            P->Next = newNode;
        }
        printf("Berhasil menambahkan %s ke wishlist!\n", namabarang);
    } else {
        printf("Gagal menambahkan barang ke wishlist (alokasi memori gagal)!\n");
    }
    printf("// Kembali ke menu utama\n");
}
