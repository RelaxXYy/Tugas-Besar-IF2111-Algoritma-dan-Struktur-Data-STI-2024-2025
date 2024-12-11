#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

boolean isQuit;

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
                exit(0);
            }
            else printf("Nama file tidak valid\n");
        } else if (current_char == 'N' || current_char == 'n'){
            printf("Kamu keluar dari PURRMART\n");
            printf("Dadah ^_^/");
            exit(0);
        } else {
            printf("Input tidak valid\n");
        }
    } else {
        printf("Kamu keluar dari PURRMART\n");
        printf("Dadah ^_^/");
        exit(0);
    }
    
}