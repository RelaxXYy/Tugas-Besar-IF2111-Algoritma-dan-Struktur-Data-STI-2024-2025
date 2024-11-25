#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include <stdio.h>

extern void start(char *filename);
extern void adv();
extern char get_current_char();
extern boolean is_eop();
extern void adv_line();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    start(argv[1]);
    if (is_eop()) {
        printf("File tidak bisa dibaca atau kosong.\n");
        return 1;
    }

    printf("Isi file: \n");
    while (!is_eop()) {
        printf("%c", get_current_char());
        adv();
    }
    printf("\n");

    printf("\nMembaca baris selanjutnya:\n");
    start(argv[1]);
    while (!is_eop()) {
        adv_line();
        printf("%c", get_current_char());
    }
    printf("\n");

    return 0;
}