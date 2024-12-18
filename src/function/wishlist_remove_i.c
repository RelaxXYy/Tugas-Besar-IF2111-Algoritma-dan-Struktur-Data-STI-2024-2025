#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

typedef struct PElement *Address;
typedef struct PElement {
    int Value;         // Simpan value wishlist, bisa diubah jadi tipe barang
    Address Next;
} Elements;

typedef struct {
    Address First;
} LinkedList;

// Fungsi untuk mengecek apakah wishlist kosong
int isWishlistEmpty(LinkedList L) {
    return L.First == NULL;
}

// Fungsi untuk menghitung panjang wishlist
int lengthWishlist(LinkedList L) {
    int count = 0;
    Address P = L.First;
    while (P != NULL) {
        count++;
        P = (*P).Next;
    }
    return count;
}

// Fungsi untuk menghapus elemen di posisi ke-i
void removeWishlist(LinkedList *L, int i) {
    if (isWishlistEmpty(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    int len = lengthWishlist(*L);
    if (i < 1 || i > len) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, barang ke-%d tidak ada di WISHLIST!\n", i);
        return;
    }

    Address P, temp;
    if (i == 1) { // Hapus elemen pertama
        temp = (*L).First;
        (*L).First = (*temp).Next;
        free(temp);
    } else { // Hapus elemen di posisi ke-i
        P = (*L).First;
        for (int j = 1; j < i - 1; j++) {
            P = (*P).Next;
        }
        temp = (*P).Next;
        (*P).Next = (*temp).Next;
        free(temp);
    }
    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
}
