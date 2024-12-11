#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void load(char* filename) {
    char file_path[MAX_LEN], default_path[MAX_LEN] = "save/";
    create_list_barang(&barangs);
    create_queue_barang(&qbarangs);
    create_list_user(&users);
    create_user(&current_user);

    if (filename == NULL) copy_string("save/default.txt", file_path);
    else concat_string(default_path, filename, file_path);
    if (fopen(file_path, "r") == NULL) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        eop = true;
        return;
    }
    start(file_path);
    int total_barang = 0;
    while (get_current_char() != '\n' && !is_eop()) {
        total_barang = total_barang * 10 + (get_current_char() - '0');
        adv();
    }
    for (int i = 0; i < total_barang; i++) {
        adv();
        int price = 0;
        while (get_current_char() != ' ' && !is_eop()) {
            price = price * 10 + (get_current_char() - '0');
            adv();
        }
        adv();
        char name[NMax];
        int j = 0;
        while (get_current_char() != '\n' && !is_eop()) {
            name[j++] = get_current_char();
            adv();
        }
        name[j] = '\0';
        add_barang(&barangs, name, price);
    }
    adv();
    int total_users = 0;
    while (get_current_char() != '\n' && !is_eop()) {
        total_users = total_users * 10 + (get_current_char() - '0');
        adv();
    }
    for (int i = 0; i < total_users; i++) {
        adv();
        int money = 0;
        char username[NMax];
        char password[NMax];
        int total_wishlist = 0;
        while (get_current_char() != ' ' && !is_eop()) {
            money = money * 10 + (get_current_char() - '0');
            adv();
        }
        adv();
        int j = 0;
        while (get_current_char() != ' ' && !is_eop()) {
            username[j++] = get_current_char();
            adv();
        }
        username[j] = '\0';
        adv();
        int k = 0;
        while (get_current_char() != '\n' && !is_eop()) {
            password[k++] = get_current_char();
            adv();
        }
        password[k] = '\0';
        add_user(&users, username, password, money);
        clear_string(username); clear_string(password);
    }
    if(!(filename == NULL)){
        is_session_started = true;
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        execute_command();
    }
    else return;
}