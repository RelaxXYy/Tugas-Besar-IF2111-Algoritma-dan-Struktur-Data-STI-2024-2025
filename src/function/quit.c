#include "save.c"
#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

boolean isQuit;
void goodbye() {
    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
    printf("     Thank you for visiting PURRMART!    \n");
    printf("         See u on another time!        \n");
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n\n");
}

void quit(){
    if (is_session_started){
        printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
        get_line();
        char current_char = current_word.tab_word[0];
        if (current_char == 'Y' || current_char == 'y'){
            printf("Masukkan nama file: ");
            get_line();
            if (validate_input(word_to_string(current_word))){
                save(word_to_string(current_word));
                printf("Kamu keluar dari PURRMART\n");
                printf("Dadah ^_^/");
                goodbye();
                exit(0);
            }
            else printf("Nama file tidak valid\n");
        } else if (current_char == 'N' || current_char == 'n'){
            printf("Kamu keluar dari PURRMART\n");
            printf("Dadah ^_^/");
            goodbye();
            exit(0);
        } else {
            printf("Input tidak valid\n");
        }
    } else {
        printf("Kamu keluar dari PURRMART\n");
        printf("Dadah ^_^/");
        goodbye();
        exit(0);
    }
    
}