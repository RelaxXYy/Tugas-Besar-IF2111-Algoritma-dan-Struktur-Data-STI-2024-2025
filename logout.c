#include <stdio.h>
#include "user.h"

// Fungsi untuk logout pengguna
void handleLogout() {
    if (loggedInIndex == -1) {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("Pengguna \"%s\" berhasil logout.\n", users[loggedInIndex].username);
        loggedInIndex = -1; // Reset status login
    }
}
