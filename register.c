#include <stdio.h>
#include "../include/user.h"
#include "../include/mesin_kata.h"
#include "../include/config.h"

void handle_register() {
    int is_registration_successful = 0; // status registrasi

    while (!is_registration_successful) {
        printf(">> REGISTER\n");

        // baca username
        char input_name[MAX_LEN];
        printf("Username: ");
        adv();       
        start_word();

        // salin current_word.tab_word ke input_name
        int i = 0;
        while (current_word.tab_word[i] != '\0' && i < MAX_LEN - 1) {
            input_name[i] = current_word.tab_word[i];
            i++;
        }
        input_name[i] = '\0';

        // validasi name: username hanya boleh satu kata
        if (!end_word) { // input mengandung spasi
            printf("Username hanya boleh satu kata. Coba lagi!! \n\n");
            while (get_current_char() != '\n' && get_current_char() != EOF) {
                adv(); 
            }
            continue; 
        }

        // baca password
        char input_password[MAX_LEN];
        printf("Password: ");
        adv();       
        start_word(); 

        // salin current_word.tab_word ke input_password
        i = 0;
        while (current_word.tab_word[i] != '\0' && i < MAX_LEN - 1) {
            input_password[i] = current_word.tab_word[i];
            i++;
        }
        input_password[i] = '\0'; 

        // validasi password: password hanya satu kata
        if (!end_word) { // input mengandung spasi
            printf("Password hanya boleh satu kata. Coba lagi!! \n\n");
            while (get_current_char() != '\n' && get_current_char() != EOF) {
                adv(); 
            }
            continue; 
        }

        // cek apakah username sudah ada
        if (is_user_exist(users, input_name)) {
            printf("Akun dengan username \"%s\" sudah digunakan. Silakan coba username lain! \n\n", input_name);
            continue; 
        }
        
        // cek kapasitas pengguna
        if (user_count(users) >= MAX_USER) {
            printf("Kapasitas pengguna penuh. Registrasi tidak dapat dilakukan.\n\n");
            break;
        }

        // tambah pengguna baru
        add_user(users, input_name, input_password, 0); 
        printf("Akun dengan username \"%s\" berhasil dibuat. Silahkan LOGIN untuk melanjutkan! \n\n", input_name);
        is_registration_successful = 1; // berhasil
    }
}
