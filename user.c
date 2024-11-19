#include "user.h"
#include "boolean.h"
#include <stdio.h>

// Variabel global
User users[MAX_USERS];
int num_users = 0;
int loggedInIndex = -1; // Awalnya tidak ada pengguna yang login

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

int isEqual(const char *str1, const char *str2) {
    return str_compare(str1, str2) == 0;  // Mengembalikan 1 jika sama, 0 jika tidak
}

// Fungsi untuk membaca data dari file secara manual
void loadUsersFromFile() {
    FILE *file = fopen("users.csv", "r"); // buka file untuk membaca
    if (file == NULL) {
        printf("File tidak ditemukan, file baru akan dibuat.\n");
        return;
    }

    char line[512];
    int i = 0;

    while (1) {
        char ch = fgetc(file);
        if (ch == EOF) break;

        // Membaca setiap baris, setiap karakter
        if (ch != '\n' && ch != '\r') {
            line[i++] = ch;
        } else {
            line[i] = '\0'; // Null-terminate line
            // Pisahkan username dan password
            char username[MAX_LEN], password[MAX_LEN];
            int j = 0, k = 0;

            while (line[j] != ',' && line[j] != '\0' && j < MAX_LEN) {
                username[k++] = line[j++];
            }
            username[k] = '\0';

            if (line[j] == ',') {
                j++;
                k = 0;
                while (line[j] != '\0' && j < MAX_LEN) {
                    password[k++] = line[j++];
                }
                password[k] = '\0';
            }

            // Menyimpan data pengguna ke array
            if (username[0] != '\0' && password[0] != '\0') {
                for (int l = 0; username[l] != '\0'; l++) {
                    users[num_users].username[l] = username[l];
                }
                for (int l = 0; password[l] != '\0'; l++) {
                    users[num_users].password[l] = password[l];
                }
                num_users++;
            }
            i = 0; // Reset line buffer
        }
    }

    fclose(file);
}

// Fungsi untuk menyimpan data ke file secara manual
void saveUsersToFile() {
    FILE *file = fopen("users.csv", "w"); // buka file untuk menulis
    if (file == NULL) {
        printf("Error membuka file untuk menulis.\n");
        return;
    }

    // Menulis data pengguna ke file
    for (int i = 0; i < num_users; i++) {
        int j = 0;
        // Menulis username ke file
        while (users[i].username[j] != '\0') {
            fputc(users[i].username[j], file);
            j++;
        }
        fputc(',', file); // Menulis koma sebagai pemisah

        j = 0;
        // Menulis password ke file
        while (users[i].password[j] != '\0') {
            fputc(users[i].password[j], file);
            j++;
        }
        fputc('\n', file); // Menulis newline
    }

    fclose(file);
}

int registerUser(const char *username, const char *password) {
    // Periksa apakah username sudah ada
    for (int i = 0; i < num_users; i++) {
        if (isEqual(users[i].username, username)) {
            return 0; // Username sudah digunakan
        }
    }

    // Menyimpan data pengguna ke dalam array tanpa menggunakan string.h
    int i = 0;
    while (username[i] != '\0' && i < MAX_LEN) {
        users[num_users].username[i] = username[i];
        i++;
    }
    users[num_users].username[i] = '\0';

    i = 0;
    while (password[i] != '\0' && i < MAX_LEN) {
        users[num_users].password[i] = password[i];
        i++;
    }
    users[num_users].password[i] = '\0';

    num_users++;

    // Menyimpan ke file setelah registrasi
    saveUsersToFile();
    return 1; // Registrasi berhasil
}

void logoutUser() {
    if (loggedInIndex == -1) {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("Pengguna \"%s\" berhasil logout.\n", users[loggedInIndex].username);
        loggedInIndex = -1; // Reset status login
    }
}

// Fungsi untuk menangani input string secara manual tanpa fgets atau scanf
void getInput(char *input, int length) {
    int i = 0;
    char ch;
    
    while (i < length - 1) {
        ch = getchar();
        if (ch == '\n') {
            break; // Menghentikan input saat newline
        }
        input[i++] = ch;
    }
    input[i] = '\0'; // Menambahkan null terminator
}
