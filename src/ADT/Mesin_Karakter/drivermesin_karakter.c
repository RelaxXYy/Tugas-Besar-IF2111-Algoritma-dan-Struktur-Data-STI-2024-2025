#include <stdio.h>
#include "mesin_karakter.h"

int main() {
    char filename[100];

    printf("Masukkan nama file (Ketik mesin_karakter.c atau mesin_karakter.h): ");
    scanf("%s", filename);

    start(filename);

    if (eop) {
        printf("File kosong atau tidak ditemukan.\n");
        return 1;
    }

    printf("Isi file:\n");
    while (!is_eop()) {
        printf("%c", get_current_char());
        adv();
    }

    printf("\nSelesai membaca file.\n");

    printf("\nMenguji fungsi adv_line (membaca baris berikutnya):\n");
    start(filename);

    while (!is_eop()) {
        adv_line();
        if (!is_eop()) {
            printf("Karakter saat ini setelah adv_line: %c\n", get_current_char());
        } else {
            printf("End of Process tercapai setelah adv_line.\n");
        }
    }

    return 0;
}