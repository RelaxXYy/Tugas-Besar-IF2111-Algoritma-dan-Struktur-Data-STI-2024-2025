#include "user.h"
#include <stdio.h>
#include <string.h>

// Variabel global
User users[MAX_USERS];
int num_users = 0;

// Manual String Comparison
int str_compare(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2; // Jika ada karakter yang berbeda
        }
        s1++;
        s2++;
    }
    return *s1 - *s2; // Periksa jika salah satu string belum selesai
}

void loadUsersFromFile() {
    FILE *file = fopen("users.csv", "r"); // buka file untuk membaca
    if (file == NULL) {
        printf("File tidak ditemukan, file baru akan dibuat.\n");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char username[MAX_LEN], password[MAX_LEN];

        // Memisahkan username dan password berdasarkan koma
        if (sscanf(line, "%[^,],%s", username, password) == 2) {
            strcpy(users[num_users].username, username);
            strcpy(users[num_users].password, password);
            num_users++;
        }
    }

    fclose(file); // Tutup file
}

void saveUsersToFile() {
    FILE *file = fopen("users.csv", "w"); // buka file untuk menulis
    if (file == NULL) {
        printf("Error membuka file untuk menulis.\n");
        return;
    }

    // Menulis data pengguna ke file
    for (int i = 0; i < num_users; i++) {
        fprintf(file, "%s,%s\n", users[i].username, users[i].password);
    }

    fclose(file); // Tutup file
}

int registerUser(const char *username, const char *password) {
    // Periksa apakah username sudah ada
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0; // Username sudah digunakan
        }
    }

    // Menyimpan data pengguna ke dalam array
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;

    // Menyimpan ke file setelah registrasi
    saveUsersToFile();

    return 1; // Registrasi berhasil
}
