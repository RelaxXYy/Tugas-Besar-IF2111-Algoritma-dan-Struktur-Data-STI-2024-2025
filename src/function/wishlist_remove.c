#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "wishlist_remove.h"

void remove_wishlist(char *input) {

    if (is_wishlist_empty(&current_user.wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    if (input[0] == '\0') {
        char response[MAX_LEN];
        printf("\nMasukkan nama barang yang akan dihapus :");
        get_line();
        copy_string(word_to_string(current_word), response);
        if(search_wishlist(&current_user.wishlist, response) != NULL) {
            printf("%s berhasil dihapus dari wishlist!\n", response);
            delete_wishlist(&current_user.wishlist, response);
        }else {
            printf("%s tidak ada di wishlist!\n", response);
        }
        return;
    }

    int index = 0, position = 0;
    while(input[index] < '0' || input[index] > '9') {
        position = position * 10 + (input[index] - '0');
        index++;
    }
    if (input[--index] != '\0') {
        printf("Penghapusan barang WISHLIST gagal dilakukan, input tidak valid!\n");
        return;
    } else if (position > 0 && position <= count_wishlist(&current_user.wishlist)) {
        Address P = current_user.wishlist.First;
        for (int i = 1; i < position; i++) {
            P = P->Next;
        }
        printf("%s berhasil dihapus dari wishlist!\n", P->Nama);
        delete_wishlist(&current_user.wishlist, P->Nama);
    } else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, input tidak valid!\n");
    }
}
