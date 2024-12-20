#include "wishlist.h"

boolean is_wishlist_empty(Wishlist *wishlist) {
    return wishlist->First == NULL;
}

void create_wishlist(Wishlist *wishlist) {
    wishlist->First = NULL;
}

Address alokasi (char *name) {
    Address P = (Address) malloc(sizeof(WishlistElement));
    if (P != NULL) {
        copy_string(name, P->Nama);
        P->Next = NULL;
        return P;
    } else {
        return NULL;
    }
}

void dealokasi (Address *P) {
    free(*P);
    *P = NULL;
}

Address search_wishlist(Wishlist *wishlist, char *name) {
    Address P = wishlist->First;
    while (P != NULL) {
        if (is_same_string(P->Nama, name)) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void insert_wishlist(Wishlist *wishlist, char *name) {
    Address newNode = alokasi(name);
    if (newNode != NULL) {
        if (wishlist->First == NULL) {
            wishlist->First = newNode;
        } else {
            Address P = wishlist->First;
            while (P->Next != NULL) {
                P = P->Next;
            }
            P->Next = newNode;
        }
    }
}

void delete_wishlist(Wishlist *wishlist, char *name) {
    Address P = wishlist->First;
    Address prev = NULL;
    while (P != NULL && !is_same_string(P->Nama, name)) {
        prev = P;
        P = P->Next;
    }
    if (P != NULL) {
        if (prev == NULL) {
            wishlist->First = P->Next;
        } else {
            prev->Next = P->Next;
        }
        dealokasi(&P);
    }
}

void swap_wishlist(Wishlist *wishlist, char *name1, char *name2) {
    Address P1 = search_wishlist(wishlist, name1);
    Address P2 = search_wishlist(wishlist, name2);
    if (P1 != NULL && P2 != NULL) {
        char temp[MAX_LEN];
        copy_string(P1->Nama, temp);
        copy_string(P2->Nama, P1->Nama);
        copy_string(temp, P2->Nama);
    }
}

int count_wishlist(Wishlist *wishlist) {
    int count = 0;
    Address P = wishlist->First;
    while (P != NULL) {
        count++;
        P = P->Next;
    }
    return count;
}

void print_wishlist(Wishlist *wishlist) {
    Address P = wishlist->First;
    while (P != NULL) {
        printf("%s\n", P->Nama);
        P = P->Next;
    }
}