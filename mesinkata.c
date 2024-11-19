#include "mesinkata.h"
#include <stdio.h>

char currentChar;
char currentWord[NMax + 1];
boolean endWord;

void advChar() {
    currentChar = getchar(); // Membaca karakter berikutnya
}

void startWord() {
    int i = 0;

    // Inisialisasi awal
    endWord = false;
    while (currentChar == ' ' || currentChar == '\t') {
        advChar(); // Lewati spasi atau tab
    }

    // Mulai membaca kata
    if (currentChar == '\n' || currentChar == EOF) {
        endWord = true; // Tandai akhir kata jika karakter baris baru atau EOF
        currentWord[0] = '\0'; // Kosongkan kata
    } else {
        // Salin karakter ke dalam currentWord
        while (currentChar != ' ' && currentChar != '\n' && currentChar != EOF && i < NMax) {
            currentWord[i] = currentChar;
            i++;
            advChar(); // Baca karakter berikutnya
        }
        currentWord[i] = '\0'; // Tambahkan null-terminator

        // Jika mencapai newline atau EOF, set endWord ke true
        if (currentChar == '\n' || currentChar == EOF) {
            endWord = true;
        }
    }
}
