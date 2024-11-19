#include <stdio.h>
#include "boolean.h"  
#include "mesinkata.h"
#include "user.h"

// Deklarasi fungsi isEqual
boolean isEqual(const char *str1, const char *str2);

// Fungsi login pengguna
boolean loginUser(const char *username, const char *password, const char *currentUser) {
    int i;

    // Periksa apakah pengguna sudah login
    if (currentUser[0] != '\0') { // Jika currentUser tidak kosong
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser);
        return false; // Tidak bisa login
    }

    // Periksa username dan password
    for (i = 0; i < num_users; i++) {
        if (isEqual(username, users[i].username) && isEqual(password, users[i].password)) {
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return true; // Login berhasil
        }
    }

    printf("Username atau password salah.\n");
    return false; // Login gagal
}

// Contoh penggunaan fungsi login (dapat digabungkan dengan program utama)
void handleLogin() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    char currentUser[MAX_LEN] = ""; // Kosongkan currentUser

    printf(">> LOGIN\n");

    // Memasukkan username
    printf("Username: ");
    startWord(); // Gunakan mesin kata untuk membaca input username
    int i = 0;
    while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
        username[i] = currentWord[i];
        i++;
    }
    username[i] = '\0'; // Null terminator

    // Memasukkan password
    printf("Password: ");
    startWord(); // Gunakan mesin kata untuk membaca input password
    i = 0;
    while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
        password[i] = currentWord[i];
        i++;
    }
    password[i] = '\0'; // Null terminator

    // Proses login
    if (loginUser(username, password, currentUser)) {
        // Jika login berhasil, set currentUser ke username
        i = 0;
        while (username[i] != '\0' && i < MAX_LEN - 1) {
            currentUser[i] = username[i];
            i++;
        }
        currentUser[i] = '\0';
    }
}

int main(){
    loadUsersFromFile();

    // Jalankan login
    printf("=== LOGIN ===\n");
    handleLogin();

    return 0; // Program selesai
}
