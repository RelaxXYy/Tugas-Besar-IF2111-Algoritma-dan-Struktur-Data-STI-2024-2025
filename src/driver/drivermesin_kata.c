#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include <stdio.h>

extern void start(char *filename);
extern void adv();
extern void adv_word();
extern void start_word();
extern char get_current_char();
extern boolean is_eop();
extern boolean end_word;
extern Word current_word;
extern void print_word(Word w);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    start_word();
    if (end_word) {
        printf("File tidak bisa dibaca atau kosong.\n");
        return 1;
    }

    printf("Isi file kata per kata: \n");
    while (!end_word) {
        print_word(current_word);
        printf(" ");
        adv_word();
    }
    printf("\n");

    return 0;
}