#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"


void wishlist_clear() {
    if (is_wishlist_empty(&current_user.wishlist)) {
        printf("Wishlist kosong!\n");
    } else {
        Address P = current_user.wishlist.First;
        while (P != NULL) {
            Address temp = P;
            P = P->Next;
            dealokasi(&temp);
        }
        create_wishlist(&current_user.wishlist);
        printf("Wishlist berhasil dihapus!\n");
    }
}