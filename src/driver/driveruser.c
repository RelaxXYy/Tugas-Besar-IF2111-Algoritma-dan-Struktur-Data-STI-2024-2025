#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

int main() {
    ListBarang barangs;
    QueueBarang qbarangs;
    StaticIntList staticIntList;
    DynamicIntList dynamicIntList;
    StaticCharList staticCharList;
    DynamicCharList dynamicCharList;
    ListUser users;
    User currentUser;

    create_list_barang(&barangs);
    create_queue_barang(&qbarangs);
    create_static_int_list(&staticIntList);
    create_dynamic_int_list(&dynamicIntList, 5);
    create_static_char_list(&staticCharList);
    create_dynamic_char_list(&dynamicCharList, 5);
    create_list_user(&users);
    create_user(&currentUser);

    add_barang(&barangs, "Kursi", 100000);
    add_barang(&barangs, "Meja", 250000);
    add_barang(&barangs, "Buku", 50000);

    print_list_barang(&barangs);

    delete_barang(&barangs, "Meja");

    printf("\nSetelah menghapus Meja:\n");
    print_list_barang(&barangs);

    enqueue_barang(&qbarangs, "Kursi");
    enqueue_barang(&qbarangs, "Buku");
    enqueue_barang(&qbarangs, "Meja");

    printf("\nQueue setelah enqueue:\n");
    print_queue_barang(&qbarangs);

    char name[MAX_LEN];
    dequeue_barang(&qbarangs, name);
    printf("\nBarang yang di-dequeue: %s\n", name);

    printf("\nQueue setelah dequeue:\n");
    print_queue_barang(&qbarangs);

    if (is_barang_exist_queue(&qbarangs, "Buku")) {
        printf("\nBuku ada di dalam queue.\n");
    } else {
        printf("\nBuku tidak ada di dalam queue.\n");
    }

    insert_static_int_list(&staticIntList, 10);
    insert_static_int_list(&staticIntList, 20);
    insert_static_int_list(&staticIntList, 30);
    printf("\nStaticIntList setelah penambahan: \n");
    for (int i = 0; i < staticIntList.count; i++) {
        printf("%d ", staticIntList.buffer[i]);
    }
    printf("\n");
    delete_static_int_list(&staticIntList, 20);
    printf("\nStaticIntList setelah penghapusan 20: \n");
    for (int i = 0; i < staticIntList.count; i++) {
        printf("%d ", staticIntList.buffer[i]);
    }
    printf("\n");

    insert_dynamic_int_list(&dynamicIntList, 100);
    insert_dynamic_int_list(&dynamicIntList, 200);
    insert_dynamic_int_list(&dynamicIntList, 300);
    printf("\nDynamicIntList setelah penambahan: \n");
    for (int i = 0; i < dynamicIntList.size; i++) {
        printf("%d ", dynamicIntList.buffer[i]);
    }
    printf("\n");
    delete_dynamic_int_list(&dynamicIntList, 200);
    printf("\nDynamicIntList setelah penghapusan 200: \n");
    for (int i = 0; i < dynamicIntList.size; i++) {
        printf("%d ", dynamicIntList.buffer[i]);
    }
    printf("\n");

    insert_static_char_list(&staticCharList, 'A');
    insert_static_char_list(&staticCharList, 'B');
    insert_static_char_list(&staticCharList, 'C');
    printf("\nStaticCharList setelah penambahan: \n");
    for (int i = 0; i < staticCharList.count; i++) {
        printf("%c ", staticCharList.buffer[i]);
    }
    printf("\n");
    delete_static_char_list(&staticCharList, 'B');
    printf("\nStaticCharList setelah penghapusan B: \n");
    for (int i = 0; i < staticCharList.count; i++) {
        printf("%c ", staticCharList.buffer[i]);
    }
    printf("\n");

    insert_dynamic_char_list(&dynamicCharList, 'X');
    insert_dynamic_char_list(&dynamicCharList, 'Y');
    insert_dynamic_char_list(&dynamicCharList, 'Z');
    printf("\nDynamicCharList setelah penambahan: \n");
    for (int i = 0; i < dynamicCharList.size; i++) {
        printf("%c ", dynamicCharList.buffer[i]);
    }
    printf("\n");
    delete_dynamic_char_list(&dynamicCharList, 'Y');
    printf("\nDynamicCharList setelah penghapusan Y: \n");
    for (int i = 0; i < dynamicCharList.size; i++) {
        printf("%c ", dynamicCharList.buffer[i]);
    }
    printf("\n");

    add_user(&users, "John", "password123", 1000);
    add_user(&users, "Jane", "pass456", 2000);
    add_user(&users, "Alice", "alice789", 3000);

    printf("\nListUser setelah penambahan: \n");
    for (int i = 0; i < users.count; i++) {
        printf("Name: %s, Money: %d\n", users.buffer[i].name, users.buffer[i].money);
    }

    if (is_user_valid(&users, "Jane", "pass456")) {
        printf("\nUser Jane berhasil divalidasi.\n");
    } else {
        printf("\nUser Jane gagal divalidasi.\n");
    }

    add_money(&users, "John", 500);
    printf("\nSetelah menambah uang ke John: \n");
    for (int i = 0; i < users.count; i++) {
        printf("Name: %s, Money: %d\n", users.buffer[i].name, users.buffer[i].money);
    }

    reduce_money(&users, "Alice", 1000);
    printf("\nSetelah mengurangi uang dari Alice: \n");
    for (int i = 0; i < users.count; i++) {
        printf("Name: %s, Money: %d\n", users.buffer[i].name, users.buffer[i].money);
    }

    free(barangs.buffer);
    free_dynamic_int_list(&dynamicIntList);
    free_dynamic_char_list(&dynamicCharList);

    return 0;
}