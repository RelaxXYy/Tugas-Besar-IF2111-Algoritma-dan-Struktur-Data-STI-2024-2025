#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "login.h"


void handle_login() {
    char name[MAX_LEN]; 
    char password[MAX_LEN];

    if (is_user_logged_in) {
        printf("Anda sudah login sebagai \"%s\". Jika ingin login sebagai user lain, silakan logout terlebih dahulu.\n", current_user.name);
        return;
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
    
    if (is_user_valid(&users, name, password)) {
        printf("Login berhasil. Selamat datang, %s!\n", name);
        current_user = users.buffer[user_index(&users, name)];
        is_user_logged_in = true; // berhasil
    } else {
        printf("Username atau Password salah. Coba lagi.\n");
    }
    return;
    
}