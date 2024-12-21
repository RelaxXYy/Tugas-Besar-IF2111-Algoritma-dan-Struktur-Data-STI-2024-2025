#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "load.h"

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
        char username[MAX_LEN];
        char password[MAX_LEN];
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
        adv();
        int total_history = 0;
        while (get_current_char() != '\n' && !is_eop()) {
            total_history = total_history * 10 + (get_current_char() - '0');
            adv();
        }
        for (int j = 0; j < total_history; i++){
            int history_count = 0, history_total_cost = 0;
            while (get_current_char() != ' ' && !is_eop()) {
                history_count = history_count * 10 + (get_current_char() - '0');
                adv();
            }
            adv();
            while (get_current_char() != '\n' && !is_eop()) {
                history_total_cost = history_total_cost * 10 + (get_current_char() - '0');
                adv();
            }
            adv();
            for (int k = 0; k < history_count; k++){
                int history_cost = 0, history_quantity = 0; char history_name[MAX_LEN]; History temp_history; HistoryElement temp_history_element;
                int l = 0;
                create_history(&temp_history);
                while (get_current_char() != ' ' && !is_eop()) {
                    history_cost = history_cost * 10 + (get_current_char() - '0');
                    adv();
                }
                adv();
                while (get_current_char() != ' ' && !is_eop()) {
                    history_quantity = history_quantity * 10 + (get_current_char() - '0');
                    adv();
                }
                adv();
                while (get_current_char() != '\n' && !is_eop()) {
                    history_name[l++] = get_current_char();
                    adv();
                }
                history_name[l] = '\0';
                adv();
                add_history_element(&temp_history_element, barangs.buffer[barang_index(&barangs, history_name)], history_quantity);
                push_history(&temp_history, temp_history_element);
                clear_string(history_name);
            }
        }
        adv();
        int total_wishlist = 0;
        while (get_current_char() != '\n' && !is_eop()) {
            total_wishlist = total_wishlist * 10 + (get_current_char() - '0');
            adv();
        }
        Wishlist temp_wishlist;
        create_wishlist(&temp_wishlist);
        for (int j = 0; j < total_wishlist; j++){
            char wishlist_name[MAX_LEN];
            int l = 0;
            while (get_current_char() != '\n' && !is_eop()) {
                wishlist_name[l++] = get_current_char();
                adv();
            }
            wishlist_name[l] = '\0';
            adv();
            insert_wishlist(&temp_wishlist, wishlist_name);
            clear_string(wishlist_name);
            users.buffer[i].wishlist = temp_wishlist;
        }
    }
    is_session_started = true;
    is_user_logged_in = false;
    
    printf("%s\n", "Konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
    printf("****************************************\n");
    printf("*    Silahkan Bergabung di PURRMART    *\n");
    printf("****************************************\n");
    printf("*   1. LOGIN                           *\n");
    printf("*   2. REGISTER                        *\n");
    printf("*   3. LOGOUT                          *\n");
    printf("****************************************\n");
    printf("*   Pilih Command atau ketik 'HELP'!   *\n");
    printf("****************************************\n");
}

// void print_loaded_data() {
//     printf("\n--- Loaded Barangs ---\n");
//     for (int i = 0; i < barangs.size; i++) {
//         printf("Barang %d: %s - %d\n", i + 1, barangs.buffer[i].name, barangs.buffer[i].price);
//     }

//     printf("\n--- Loaded Users ---\n");
//     for (int i = 0; i < users.count; i++) {
//         User *user = &users.buffer[i];
//         printf("User %d: %s - Money: %d\n", i + 1, user->name, user->money);
//         // Print history
//         printf("  History (%d entries):\n", user->riwayat_pembelian.IndexTop + 1);
//         for (int j = 0; j <= user->riwayat_pembelian.IndexTop; j++) {
//             HistoryElement *he = &user->riwayat_pembelian.HistoryElements[j];
//             printf("    Transaction %d - Total Price: %d\n", j + 1, he->TotalPrice);
//             for (int k = 0; k < he->HistoryBarangCount; k++) {
//                 printf("      %s x%d - Price per unit: %d\n",
//                        he->HistoryBarangs[k].buffer.name,
//                        he->HistoryBarangs[k].amount,
//                        he->HistoryBarangs[k].buffer.price);
//             }
//         }
//         printf("  Wishlist (%d items):\n", count_wishlist(&user->wishlist));
//         print_wishlist(&user->wishlist);
//     }
// }

// int main() {
//     load("../../../save/default.txt");
//     print_loaded_data();
//     return 0;
// }