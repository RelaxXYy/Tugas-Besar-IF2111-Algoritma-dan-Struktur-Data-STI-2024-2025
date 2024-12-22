#include "console.h"


void execute_command() {
    printf("\n");
    printf("Ketik command atau \"Help\"\n");
    printf(">>> ");
    get_line();
    char command[MAX_LEN], first_word[MAX_LEN], no_first_word[MAX_LEN], no_first_and_second_word[MAX_LEN], input[MAX_LEN];
    copy_string(word_to_string(current_word), command);
    copy_string(command, input);
    get_first_word(command, first_word);
    upper_string(command);
    upper_string(first_word);

    if (is_same_string(command, "HELP") == true) {
        help();
    } else if (is_same_string(first_word, "LOAD") == true) {
        ignore_first_word(input, no_first_word);
        load(no_first_word);
    } else if (is_same_string(command, "START") == true) {
        start_command();
    } else if (is_same_string(command, "LOGIN") == true && is_session_started == true) {
        handle_login();
    } else if (is_same_string(command, "LOGOUT") == true && is_session_started == true) {
        handle_logout();
    } else if (is_same_string(command, "REGISTER") == true && is_session_started == true) {
        handle_register();
    } else if (is_same_string(command, "PROFILE") == true && is_user_logged_in && is_session_started == true) {
        profile();
    } else if (is_same_string(command, "WORK") == true && is_user_logged_in == true && is_session_started == true) {
        handle_work(&current_user);
    } else if (is_same_string(command, "WORK CHALLENGE") == true && is_user_logged_in == true && is_session_started == true) {
        challenge();
    } else if (is_same_string(first_word, "STORE") == true && is_user_logged_in == true && is_session_started == true) {
        ignore_first_word(command, no_first_word);
        if (is_same_string(no_first_word, "REQUEST") == true && is_user_logged_in == true && is_session_started == true) store_request_main();
        else if (is_same_string(no_first_word, "SUPPLY") == true && is_user_logged_in == true && is_session_started == true) store_supply_main();
        else if (is_same_string(no_first_word, "REMOVE") == true && is_user_logged_in == true && is_session_started == true) store_remove_main();
        else if (is_same_string(no_first_word, "LIST") == true && is_user_logged_in == true && is_session_started == true) store_list_main();
        else printf("Unknown command: %s\n", input);
    } else if (is_same_string(first_word, "CART") == true && is_user_logged_in == true && is_session_started == true) {
        ignore_first_word(command, no_first_word);
        if (is_same_string(no_first_word, "SHOW") == true && is_user_logged_in == true && is_session_started == true) cart_show();
        else if (is_same_string(no_first_word, "PAY") == true && is_user_logged_in == true && is_session_started == true) cart_pay_main();
        else if (is_same_string(no_first_word, "REMOVE") == true && is_user_logged_in == true && is_session_started == true) store_remove_main();
        else if (is_same_string(no_first_word, "ADD") == true && is_user_logged_in == true && is_session_started == true) store_list_main();
        else printf("Unknown command: %s\n", input);
    } else if (is_same_string(first_word, "WISHLIST") == true && is_user_logged_in == true && is_session_started == true) {
        ignore_first_word(command, no_first_word);
        if (is_same_string(no_first_word, "ADD") == true && is_user_logged_in == true && is_session_started == true) wishlist_add_main();
        else if (is_same_string(no_first_word, "CLEAR") == true && is_user_logged_in == true && is_session_started == true) wishlist_clear();
        else if (is_same_string(no_first_word, "SHOW") == true && is_user_logged_in == true && is_session_started == true) wishlist_show();
        else if (is_same_string(no_first_word, "REMOVE") == true && is_user_logged_in == true && is_session_started == true){
            ignore_first_word(no_first_word, no_first_and_second_word);
            wishlist_remove(no_first_and_second_word);
        }
        else if (is_same_string(no_first_word, "SWAP") == true && is_user_logged_in == true && is_session_started == true){
            char nama_barang1[MAX_LEN], nama_barang2[MAX_LEN];
            ignore_first_word(no_first_word, no_first_and_second_word);
            get_first_word(no_first_and_second_word, nama_barang1);
            ignore_first_word(no_first_and_second_word, no_first_word);
            get_first_word(no_first_word, nama_barang2);
            if(is_same_string(no_first_word, nama_barang2)){
                wishlist_swap(nama_barang1, nama_barang2);
            }
            else printf("Unknown command: %s\n", input);
        }
        else printf("Unknown command: %s\n", input);
    } else if (is_same_string(first_word, "SAVE") == true && is_user_logged_in == true && is_session_started == true) {
        ignore_first_word(input, no_first_word);
        save(no_first_word);
    } else if (is_same_string(command, "QUIT" ) == true) {
        quit();
    } else if (is_same_string(command, "BIO WEAPON") == true && is_session_started == true && is_user_logged_in == true) {
        bioweapon_main();
    } else printf("Unknown command: %s\n", input);
    execute_command();
}
