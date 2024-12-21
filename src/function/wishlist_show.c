#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "wishlist_show.h"

void wishlist_show() {
    if (is_wishlist_empty(&current_user.wishlist)) {
        printf("Wishlist kosong!\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        Address P = current_user.wishlist.First; int i = 1;
        while (P != NULL) {
            printf("%d. %s\n", i, P->Nama);
            P = P->Next;
            i++;
        }
    }
}