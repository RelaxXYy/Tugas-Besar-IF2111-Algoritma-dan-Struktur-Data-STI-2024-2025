#include <stdio.h>
#include <stdlib.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

// is_same_string sama copy_string keknya bisa diganti????

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

int store_item_exists(Store *barangs, char *namabarang) {
    for (int i = 0; i < barangs->Count; i++) {
        if (is_same_string(barangs->Items[i], namabarang)) {
            return 1; 
        }
    }
    return 0; 
}

int wishlist_item_exists(LinkedListChar *wishlist, char *namabarang) {
    Address P = wishlist->First;
    while (P != NULL) {
        if (is_same_string(P->Nama, namabarang)) {
            return 1; 
        }
        P = P->Next;
    }
    return 0;
}

void wishlist_add(LinkedListChar *wishlist, Store *barangs, char *namabarang) {
    if (!store_item_exists(barangs, namabarang)) { 
        printf("Tidak ada barang dengan nama %s di toko!\n", namabarang);
        return;
    }

    if (wishlist_item_exists(wishlist, namabarang)) {
        printf("%s sudah ada di wishlist!\n", namabarang);
        return;
    }

    Address newNode = (Address) malloc(sizeof(ElementsChar));
    if (newNode != NULL) {
        copy_string(newNode->Nama, namabarang);
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
