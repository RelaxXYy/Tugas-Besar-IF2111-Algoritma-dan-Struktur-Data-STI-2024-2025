#include <stdio.h>
#include "user.h"
#include "mesinkata.h"

void handleRegister() {
    printf(">> REGISTER\n");

    // Membaca username
    printf("Username: ");
    startWord(); // Memulai pembacaan kata
    char username[MAX_LEN];
    int i = 0;
    while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
        username[i] = currentWord[i];
        i++;
    }
    username[i] = '\0'; // Null terminator

    if (endWord == false || currentChar != '\n') { // Masih ada kata lain setelahnya
        printf("Username hanya boleh satu kata.\n");
        return;
    }

    // Membaca password
    printf("Password: ");
    startWord(); // Membaca input password
    char password[MAX_LEN];
    i = 0;
    while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
        password[i] = currentWord[i];
        i++;
    }
    password[i] = '\0'; // Null terminator

    if (endWord == false || currentChar != '\n') { // Masih ada kata lain setelahnya
        printf("Password hanya boleh satu kata.\n");
        return;
    }

    // Proses registrasi
    int result = registerUser(username, password);

    if (result == 1) {
        printf("Akun dengan username \"%s\" berhasil dibuat.\n", username);
    } else if (result == 0) {
        printf("Username \"%s\" sudah digunakan.\n", username);
    } else {
        printf("Kapasitas pengguna penuh.\n");
    }
}

int main() {
    loadUsersFromFile(); // Memuat pengguna dari file saat program mulai

    // Fungsi lain atau menu untuk program

    handleRegister(); // Registrasi pengguna

    return 0;
}
