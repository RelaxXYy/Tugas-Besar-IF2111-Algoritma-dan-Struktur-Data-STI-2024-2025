#include <stdio.h>
#include "user.h"

int main() {
    ListUser users;
    create_list_user(&users);

    printf("Menambahkan user ke sistem...\n");
    add_user(&users, "Joko", "Jokokeren", 999);
    add_user(&users, "Jono", "Jonomantap", 19991919);
    add_user(&users, "Joyo", "Joyojoyo123", 9999999);

    printf("Jumlah user: %d\n", user_count(&users));

    char *name = "Joko";
    char *password = "Jokokeren";
    if (is_user_valid(&users, name, password)) {
        printf("Login berhasil untuk user %s.\n", name);
    } else {
        printf("Login gagal untuk user %s.\n", name);
    }

    printf("Menambahkan uang ke user JOno...\n");
    add_money(&users, "JOno", 500);

    printf("Mengurangi uang dari user Joyo...\n");
    reduce_money(&users, "Joyo", 300);

    printf("Informasi user:\n");
    for (int i = 0; i < users.count; i++) {
        User u = users.buffer[i];
        printf("Nama: %s, Uang: %d\n", u.name, u.money);
    }

    return 0;
}