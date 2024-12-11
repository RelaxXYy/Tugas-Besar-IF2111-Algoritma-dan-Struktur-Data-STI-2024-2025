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