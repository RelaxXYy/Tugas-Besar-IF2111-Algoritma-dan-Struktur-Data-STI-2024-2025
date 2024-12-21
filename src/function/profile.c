#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "profile.h"

void profile() {

    if (current_user.name[0] != '\0') {
    printf("Nama    : %s\n", current_user.name);
    printf("Saldo   : %d\n", current_user.money);
    }

    else {
        printf("Tidak ada user yang aktif.\n");
    }

}