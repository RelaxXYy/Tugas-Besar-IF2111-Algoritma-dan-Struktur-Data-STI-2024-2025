#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

int driver_wishlist() {
    Wishlist wishlist;
    create_wishlist(&wishlist);

    printf("Apakah wishlist kosong? %s\n", is_wishlist_empty(&wishlist) ? "Ya" : "Tidak");

    printf("Menambahkan elemen ke wishlist...\n");
    insert_wishlist(&wishlist, "AK47");
    insert_wishlist(&wishlist, "KAR49");
    insert_wishlist(&wishlist, "M4");

    printf("Isi wishlist:\n");
    print_wishlist(&wishlist);

    printf("Wishlist berisi %d elemen.\n", count_wishlist(&wishlist));

    char *searchItem = "KAR49";
    Address found = search_wishlist(&wishlist, searchItem);
    if (found != NULL) {
        printf("%s ditemukan di wishlist.\n", searchItem);
    } else {
        printf("%s tidak ditemukan di wishlist.\n", searchItem);
    }

    printf("Menghapus elemen \"M4\" dari wishlist...\n");
    delete_wishlist(&wishlist, "M4");

    printf("Isi wishlist setelah penghapusan:\n");
    print_wishlist(&wishlist);

    printf("Menukar elemen \"AK47\" dan \"KAR49\"...\n");
    swap_wishlist(&wishlist, "AK47", "KAR49");

    printf("Isi wishlist setelah penukaran:\n");
    print_wishlist(&wishlist);

    return 0;
}