#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "work_challenge.h"

void tebak_angka(){
    int number = random_number_generator(1, 100);
    int chance = 10, earning = 500;
    for (int i = 0; i < chance; i++){
        printf("Tebak angka (1-100) (sisa kesempatan:%d) : ", chance - i);
        start(NULL);
        int guess = 0;
        boolean valid_input = true;
        while (get_current_char() != '\n' && !is_eop()) {
            // input berupa angka
            if (get_current_char() < '0' || get_current_char() > '9') {
                valid_input = false;
            } else {
                guess = guess * 10 + (get_current_char() - '0');
            }
            adv();
        }

        // jika inputan tidak valid (huruf or someting)
        if (!valid_input || guess < 1 || guess > 100) {
            printf("Input tidak valid. Masukkan angka antara 1-100.\n");
            i--; // tidak mengurangi jumlah kesempatan
            continue;
        }

        if (guess == number){
            printf("Selamat, kamu berhasil menebak angka! Anda mendapatkan uang sebanyak %d\n", earning);
            current_user.money += earning;
            return;
        } else if (guess < number){
            printf("Angka terlalu kecil\n");
        } else {
            printf("Angka terlalu besar\n");
        }
        earning -= 50;
    }
    printf("Kamu gagal menebak angka. Angka yang benar adalah %d\n", number);
    return;
}

void wordl399(){

    int index = random_number_generator(0, 99), chance = 6;
    char word[6], answer[6][11], guess[6];
    boolean valid = true;
    copy_string(wordlist[index], word);
    upper_string(word);
    printf("Welcome to WORDL399, you have 6 chance to guess the word\n\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < i; j++){
            for (int k = 0; k < 5; k++){
                if (valid) printf("%c%c ", answer[j][k * 2], answer[j][(k * 2) + 1]);
            }
            if (valid) printf("\n");
        }
        for (int j = 6; j > i; j--){
            if (valid) printf("_ _ _ _ _\n");
        }
        printf("Masukan kata tebakan Anda: ");
        get_line();
        printf("\n");
        copy_string(word_to_string(current_word), guess);
        upper_string(guess);
        if(!is_letter(guess)){
            printf("Kata hanya berisi huruf\n");
            i--;
            valid = false;
            continue;
        }
        if(string_length(guess) != 5){
            printf("Kata harus memiliki panjang 5\n");
            i--;
            valid = false;
            continue;
        }
        valid = true;
        if (is_same_string(guess, word)){
            printf("Selamat, kamu berhasil menebak kata! Anda mendapatkan uang sebanyak 1500\n");
            current_user.money += 1500;
            return;
        }
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (guess[j] == word[k]){
                    if (j == k){
                        answer[i][j * 2] = guess[j];
                        answer[i][j * 2 + 1] = ' ';
                    } 
                    else if (answer[i][j * 2 + 1] != ' '){
                        answer[i][j * 2] = guess[j];
                        answer[i][j * 2 + 1] = '*';
                    }

                }
            }
            if (answer[i][j * 2 + 1] != ' ' && answer[i][j * 2 + 1] != '*'){
                answer[i][j * 2] = guess[j];
                answer[i][j * 2 + 1] = '%';
            }
        }
        answer[i][10] = '\0';
    }
    for (int j = 0; j < 6; j++){
        for (int k = 0; k < 5; k++){
            printf("%c%c ", answer[j][k * 2], answer[j][(k * 2) + 1]);
        }
        printf("\n");
    }
    printf("\n\nKamu gagal menebak kata. Kata yang benar adalah %s\n", word);
}

void quantum_wordl3(){
//     int number_1 = random_number_generator(0, 99);
//     int number_2 = random_number_generator(0, 99);
//     while (number_1 == number_2){
//         number_2 = random_number_generator(0, 99);
//     }
//     int number_3 = random_number_generator(0, 99);
//     while (number_3 == number_1 || number_3 == number_2){
//         number_3 = random_number_generator(0, 99);
//     }
//     int number_4 = random_number_generator(0, 99);
//     while (number_4 == number_1 || number_4 == number_2 || number_4 == number_3){
//         number_4 = random_number_generator(0, 99);
//     }
//     char *word_1 = wordlist[number_1], *word_2 = wordlist[number_2], *word_3 = wordlist[number_3], *word_4 = wordlist[number_4];
//     char guess[6], answer1[6][12], answer2[6][12], answer3[6][12], answer4[6][12];
//     printf("Welcome to Quantum WORDL3, you have 10 chance to guess the word\n");
//     for (int i = 0; i < 6; i++){
//         for (int j = 0; j < 6-i; j++){
//             printf("_ _ _ _ _  _ _ _ _ _  _ _ _ _ _  _ _ _ _ _\n");
//         }
//         printf("Masukan kata tebakan Anda: ");
//         get_line();
//         copy_string(word_to_string(current_word), guess);
//         while (string_length(guess) != 5){
//             printf("Kata harus memiliki panjang 5\n");
//             printf("Masukan kata tebakan Anda: ");
//             get_line();
//             copy_string(word_to_string(current_word), guess);
//         }
//         if (is_same_string(guess, wor)){
//             printf("Selamat, kamu berhasil menebak kata! Anda mendapatkan uang sebanyak 1500\n");
//             add_money(&users, current_user.name, 1500);
//             return;
//         }
//         for (int j = 0; j < i; j++){
//             for (int k = 0; k < 5; k++){
//                 printf("%c%c ", answer[j][k * 2], answer[j][(k * 2) + 1]);
//             }
//             printf("\n");
//         }
//         for (int k = 0; k < 5; k++){
//             printf("%c%c ", guess[k], test_wordl399(word, guess[k], k));
//             answer[i][k * 2] = guess[k];
//             if (test_wordl399(word, guess[k], k) == '\0') answer[i][(k * 2) + 1] = ' ';
//             else answer[i][(k * 2) + 1] = test_wordl399(word, guess[k], k);
//         }
//         answer[i][10] = '\0';
//         printf("\n");
//     }
//     printf("Kamu gagal menebak kata. Kata yang benar adalah %s\n", word);
// }
}

ListChallenge challenges = {
    .buffer = {
        {"Tebak Angka", tebak_angka, 1, 200},
        {"W0RDL399", wordl399, 2, 500},
        {"Quantum WORDL3", quantum_wordl3, 3, 15000}
    },
    .count = 2
};

void challenge(){
    char response[MAX_LEN], function[MAX_LEN], str[MAX_LEN]; boolean valid = false;
    printf("Daftar challenge yang tersedia:\n");
    for (int i = 0; i < challenges.count; i++){
        printf("%d. %s (biaya main = %d)\n", challenges.buffer[i].token, challenges.buffer[i].name, challenges.buffer[i].cost);
    }
    printf("Masukkan nomor challenge yang dipilih: ");
    get_line();
    copy_string(word_to_string(current_word), response);
    // while(!valid){

    // }
    // while(response[i] != '\0'){
    //     if(!(response[i] < '0' || response[i] > '9')){
    //         return false;
    //     }
    //     i++;
    // }
    for(int i = 0; i < challenges.count; i++){
        int_to_string(challenges.buffer[i].token, str);
        if(is_same_string(response, str)){
            if(current_user.money >= challenges.buffer[i].cost){ 
                current_user.money -= challenges.buffer[i].cost;
                challenges.buffer[i].function();
                printf("Uang anda sekarang: %d\n", current_user.money);
            }
            else printf("Uang tidak cukup. Silakan coba lagi\n");
            return;
        }
    }
    printf("Challenge tidak valid. Silakan coba lagi.\n");
}
