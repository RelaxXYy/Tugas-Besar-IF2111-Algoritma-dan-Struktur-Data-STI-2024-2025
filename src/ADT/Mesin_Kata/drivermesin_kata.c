#include <stdio.h>
#include "mesin_kata.h"

int main() {
    Word test_word;
    char input_string[100];
    char first_word[100];
    char new_string[100];
    char concatenated[200];

    printf("Masukkan string untuk diubah ke Word: ");
    scanf("%s", input_string);
    test_word = string_to_word(input_string);
    printf("Word hasil konversi: ");
    print_word(test_word);

    printf("\nMasukkan string kedua untuk dibandingkan: ");
    char second_string[100];
    scanf("%s", second_string);
    Word second_word = string_to_word(second_string);
    if (is_same_word(test_word, second_word)) {
        printf("Word sama!\n");
    } else {
        printf("Word berbeda!\n");
    }

    printf("\nMasukkan kalimat (max 100 karakter): ");
    getchar();
    fgets(input_string, sizeof(input_string), stdin);

    get_first_word(input_string, first_word);
    printf("Kata pertama: %s\n", first_word);

    ignore_first_word(input_string, new_string);
    printf("Kalimat tanpa kata pertama: %s\n", new_string);

    concat_string(first_word, new_string, concatenated);
    printf("Hasil penggabungan kata pertama dan sisa kalimat: %s\n", concatenated);

    if (is_blank_exist(input_string)) {
        printf("Kalimat mengandung spasi.\n");
    } else {
        printf("Kalimat tidak mengandung spasi.\n");
    }

    if (validate_input(input_string)) {
        printf("Input valid, tidak lebih dari 100 karakter.\n");
    } else {
        printf("Input tidak valid.\n");
    }

    return 0;
}