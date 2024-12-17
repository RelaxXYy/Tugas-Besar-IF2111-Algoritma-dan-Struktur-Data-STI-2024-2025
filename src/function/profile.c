#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void profile() {

    if (current_user.name[0] != '\0') {
    printf("Nama    : %s\n", current_user.name);
    printf("Saldo   : %d\n", current_user.money);
    }

    else {
        printf("Tidak ada user yang aktif.\n");
    }

}