#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void handle_register() {
    char name[MAX_LEN]; 
    char password[MAX_LEN];

    if (is_user_logged_in) {
        printf("Anda sudah login sebagai %s. Jika ingin register sebagai user lain, silakan logout terlebih dahulu.\n", current_user.name);
        execute_command();
    }

    printf("Username: ");  
    boolean blank_exist = true, valid = false;
    while (blank_exist || !valid) {
        get_line();
        blank_exist = is_blank_exist(word_to_string(current_word));
        valid = is_letter_or_digit(word_to_string(current_word));
        if (blank_exist || !valid) {
            printf("Username terdapat karakter yang tidak diperbolehkan. Coba lagi!! \nUsername: ");
        }
        else if(!validate_input(word_to_string(current_word))){
            printf("Username tidak boleh kosong. Coba lagi!! \nUsername: ");
            valid = false;
        }
        else break;
    }
    copy_string(word_to_string(current_word), name);
    
    printf("Password: ");
    blank_exist = true, valid = false;
    while (blank_exist || !valid) {
        get_line();
        blank_exist = is_blank_exist(word_to_string(current_word));
        if (blank_exist) {
            printf("Password terdapat spasi. Coba lagi!! \nPassword: ");
        }
        else if(!validate_input(word_to_string(current_word))){
            printf("Password tidak boleh kosong. Coba lagi!! \nPassword: ");
            valid = false;
        }
        else break;
    }
    copy_string(word_to_string(current_word), password);

    if (is_user_exist(&users, name)) {
        printf("Akun dengan username \"%s\" sudah digunakan. Silakan coba username lain! \n", name);
        execute_command();
    }
    
    if (user_count(&users) == MAX_USER) {
        printf("Kapasitas pengguna penuh. Registrasi tidak dapat dilakukan.\n");
        execute_command();
    }
    add_user(&users, name, password, 0);
    current_user = users.buffer[user_index(&users, name)];
    printf("Akun dengan username \"%s\" berhasil dibuat. Silahkan LOGIN untuk melanjutkan! \n", name);
    is_user_logged_in = true;
    execute_command();
}