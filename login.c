#include <stdio.h>
#include "../include/user.h"
#include "../include/mesin_kata.h"
#include "../include/config.h"
#include "../include/boolean.h"

// login pengguna
boolean login_user(char *name, char *password, char *current_user) {
    // apakah pengguna sudah login
    if (current_user[0] != '\0') { 
        printf("Kamu masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu! \n", current_user);
        return false; 
    }
    
    // validasi name dan password
    if (is_user_valid(users, name, password)) {
        return true; 
    }
    return false; 
}

void handle_login() {
    char name[MAX_LEN]; 
    char password[MAX_LEN];
    char current_user[MAX_LEN] = ""; 

    int login_success = 0; // status login
    while (!login_success) {
        printf(">> LOGIN\n");

        printf("Username: ");  
        adv();       
        start_word(); 

        // salin current_word.tab_word ke name
        int i = 0;
        while (current_word.tab_word[i] != '\0' && i < MAX_LEN - 1) {
            name[i] = current_word.tab_word[i];
            i++;
        }
        name[i] = '\0'; 

        // validasi input username
        if (!end_word) { 
            printf("Username hanya boleh satu kata. Coba lagi!! \n\n");
            while (get_current_char() != '\n' && get_current_char() != EOF) {
                adv(); 
            }
            continue; 
        }

        printf("Password: ");
        adv();       
        start_word(); 

        // salin current_word.tab_word ke password
        i = 0;
        while (current_word.tab_word[i] != '\0' && i < MAX_LEN - 1) {
            password[i] = current_word.tab_word[i];
            i++;
        }
        password[i] = '\0'; 

        // validasi input password
        if (!end_word) { 
            printf("Password hanya boleh satu kata. Coba lagi!! \n\n");
            while (get_current_char() != '\n' && get_current_char() != EOF) {
                adv(); 
            }
            continue; 
        }

        // proses login
        if (login_user(name, password, current_user)) {
            printf("Login berhasil. Selamat datang, %s!\n", name);
            copy_string(name, current_user);
            login_success = 1; // berhasil
        } else {
            printf("Username atau password salah. Coba lagi.\n\n");
        }
    }
}
