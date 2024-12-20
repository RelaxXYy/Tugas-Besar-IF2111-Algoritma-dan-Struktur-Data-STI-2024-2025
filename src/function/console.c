#include "all_function_headers.h"
#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

void execute_command() {
    printf("Ketik command atau \"Help\"\n");
    printf(">>> ");
    get_line();
    printf("\n");
    char command[MAX_LEN], first_word[MAX_LEN], no_first_word[MAX_LEN], input[MAX_LEN];
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
    } else if (is_same_string(command, "PROFILE") == true && is_session_started == true) {
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
    } else if (is_same_string(first_word, "SAVE") == true && is_user_logged_in == true && is_session_started == true) {
        ignore_first_word(input, no_first_word);
        save(no_first_word);
    } else if (is_same_string(command, "QUIT" ) == true) {
        printf("Kamu keluar dari PURRMART, %s\n", input);
        quit();
    } else if (is_same_string(command, "BIO WEAPON") == true && is_session_started == true && is_user_logged_in == true) {
        bioweapon_main();
    } else printf("Unknown command: %s\n", input);
    execute_command();
}
