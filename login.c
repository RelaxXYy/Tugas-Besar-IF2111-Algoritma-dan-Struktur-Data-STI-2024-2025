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
            return true; // Login berhasil
        }
    }
    return false; // Login gagal
}

// Contoh penggunaan fungsi login (dapat digabungkan dengan program utama)
void handleLogin() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    char currentUser[MAX_LEN] = ""; // Kosongkan currentUser

    int loginSuccess = 0; // Flag untuk status login

    while (!loginSuccess) {
        printf(">> LOGIN\n");

        // Input username
        printf("Username: ");
        advChar();   // Mulai pembacaan karakter pertama
        startWord(); // Baca input username

        // Salin currentWord ke username
        int i = 0;
        while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
            username[i] = currentWord[i];
            i++;
        }
        username[i] = '\0'; // Null terminator

        // Validasi input username
        if (!endWord) { // Jika input username memiliki lebih dari satu kata
            printf("Username hanya boleh satu kata. Coba lagi.\n\n");
            while (currentChar != '\n' && currentChar != EOF) {
                advChar(); // Lewati sisa input
            }
            continue; // Ulangi loop untuk meminta input ulang
        }

        // Input password
        printf("Password: ");
        advChar();   // Mulai pembacaan karakter pertama
        startWord(); // Baca input password

        // Salin currentWord ke password
        i = 0;
        while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
            password[i] = currentWord[i];
            i++;
        }
        password[i] = '\0'; // Null terminator

        // Validasi input password
        if (!endWord) { // Jika input password memiliki lebih dari satu kata
            printf("Password hanya boleh satu kata. Coba lagi.\n\n");
            while (currentChar != '\n' && currentChar != EOF) {
                advChar(); // Lewati sisa input
            }
            continue; // Ulangi loop untuk meminta input ulang
        }

        // Proses login
        if (loginUser(username, password, currentUser)) {
            printf("Login berhasil. Selamat datang, %s!\n", username);
            loginSuccess = 1; // Login berhasil
        } else {
            printf("Username atau password salah. Coba lagi.\n\n");
        }
    }
}

int main(){
    loadUsersFromFile();

    // Jalankan login
    printf("=== LOGIN ===\n");
    handleLogin();

    return 0; // Program selesai
}
