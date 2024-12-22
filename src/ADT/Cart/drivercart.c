#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

int main() {
    Cart cart;

    create_cart(&cart);
    printf("Apakah keranjang kosong? %s\n", is_cart_empty(&cart) ? "Ya" : "Tidak");

    printf("Menambahkan AWM, KAR49, dan TM01 ke keranjang.\n");
    insert_cart(&cart, "AWM", 10);
    insert_cart(&cart, "KAR49", 5);
    insert_cart(&cart, "TM01", 7);

    printf("Jumlah barang dalam keranjang sekarang adalah %d\n", cart.count);

    printf("Apakah \"AWM\" ada di keranjang? %s\n", is_exist_in_cart(&cart, "AWM") ? "Ya" : "Tidak");
    printf("Apakah \"M4\" ada di keranjang? %s\n", is_exist_in_cart(&cart, "M4") ? "Ya" : "Tidak");

    printf("Jumlah \"AWM\" dalam keranjang adalah %d\n", cart_value(&cart, "AWM"));

    printf("\"AWM\" akan dihapus dari keranjang\n");
    delete_cart(&cart, "AWM");
    printf("Apakah \"AWM\" ada di keranjang? %s\n", is_exist_in_cart(&cart, "AWM") ? "Ya" : "Tidak");

    printf("Apakah keranjang penuh? %s\n", is_cart_full(&cart) ? "Ya" : "Tidak");

    printf("Menambahkan lebih banyak barang...\n");
    for (int i = 0; i < MAX_LIST; i++) {
        char item[10];
        sprintf(item, "Item%d", i);
        insert_cart(&cart, item, i + 1);
        if (is_cart_full(&cart)) {
            printf("Keranjang penuh setelah menambahkan %d barang.\n", i + 1);
            break;
        }
    }

    printf("Jumlah barang dalam keranjang setelah diisi hingga penuh adalah %d\n", cart.count);

    return 0;
}