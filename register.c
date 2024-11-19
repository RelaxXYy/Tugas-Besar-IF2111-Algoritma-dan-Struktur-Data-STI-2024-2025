#include <stdio.h>
#include "user.h"
#include "mesinkata.h"

void handleRegister() {
    int registrationSuccess = 0; // Flag untuk status registrasi

    while (!registrationSuccess) {
        printf(">> REGISTER\n");

        // Membaca username
        char username[MAX_LEN];
        printf("Username: ");
        advChar();   // Inisialisasi baca karakter pertama
        startWord(); // Mulai pembacaan kata

        // Salin currentWord ke username
        int i = 0;
        while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
            username[i] = currentWord[i];
            i++;
        }
        username[i] = '\0'; // Null terminator

        // Validasi username
        if (!endWord) { // Jika ada spasi di input username
            printf("Username hanya boleh satu kata. Coba lagi.\n\n");
            while (currentChar != '\n' && currentChar != EOF) {
                advChar(); // Lewati sisa input untuk memulai ulang
            }
            continue; // Ulangi dari awal loop
        }

        // Membaca password
        char password[MAX_LEN];
        printf("Password: ");
        advChar();   // Mulai pembacaan baru
        startWord(); // Baca password

        // Salin currentWord ke password
        i = 0;
        while (currentWord[i] != '\0' && i < MAX_LEN - 1) {
            password[i] = currentWord[i];
            i++;
        }
        password[i] = '\0'; // Null terminator

        // Validasi password
        if (!endWord) { // Jika ada spasi di input password
            printf("Password hanya boleh satu kata. Coba lagi.\n\n");
            while (currentChar != '\n' && currentChar != EOF) {
                advChar(); // Lewati sisa input untuk memulai ulang
            }
            continue; // Ulangi dari awal loop
        }

        // Proses registrasi
        int result = registerUser(username, password);

        if (result == 1) {
            printf("Akun dengan username \"%s\" berhasil dibuat.\n\n", username);
            registrationSuccess = 1; // Registrasi berhasil
        } else if (result == 0) {
            printf("Username \"%s\" sudah digunakan. Silakan coba username lain.\n\n", username);
        } else {
            printf("Kapasitas pengguna penuh. Registrasi tidak dapat dilakukan.\n\n");
            break; // Jika kapasitas penuh
        }
    }
}

int main() {
    loadUsersFromFile(); // Memuat pengguna dari file saat program mulai

    // Fungsi lain atau menu untuk program

    handleRegister(); // Registrasi pengguna

    return 0;
}
