#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

void copystring(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void wishlistswap(LinkedListChar *wishlist, int pos_1, int pos_2) {
    if (wishlist->First == NULL) {
        printf("Wishlist kosong, tidak ada yang bisa ditukar!\n");
        return;
    }

    if (pos_1 == pos_2) {
        printf("Posisi yang dipilih sama! Tidak ada yang perlu ditukar\n");
        return;
    }

    Address P1 = NULL, P2 = NULL, P = wishlist->First;
    int index = 1; 
    while (P != NULL) {
        if (index == pos1) P1 = P;
        if (index == pos2) P2 = P;
        P = P->Next;
        index++;
    }

    if (P1 == NULL || P2 == NULL) {
        printf("Gagal menukar posisi! Salah satu atau kedua posisi tidak valid! \n");
        return;
    }

    char temp[sizeof(P1->Nama)]; 
    copystring(temp, P1->Nama);
    copystring(P1->Nama, P2->Nama);
    copystring(P2->Nama, temp);

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", P1->Nama, P2->Nama);
    printf("Urutan %s berubah menjadi %d, sebaliknya urutan %s menjadi %d\n", P1->Nama, pos2, P2->Nama, pos1);
}