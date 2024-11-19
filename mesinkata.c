#include "mesinkata.h"
#include <stdio.h>

char currentChar;
char currentWord[NMax + 1];
boolean endWord;

void advChar() {
    currentChar = getchar();
}

void startWord() {
    int i = 0;

    // Lewati spasi di awal
    while (currentChar == ' ' || currentChar == '\t') {
        advChar();
    }

    // Mulai membaca kata
    while (currentChar != ' ' && currentChar != '\t' && currentChar != '\n' && currentChar != EOF) {
        currentWord[i] = currentChar;
        i++;
        advChar();
    }

    currentWord[i] = '\0'; // Tambahkan null terminator

    // Periksa apakah akhir kata atau akhir input
    endWord = (currentChar == '\n' || currentChar == EOF);
}

// Lanjut membaca kata berikutnya
void advanceWord() {
    startWord();
}

// Mendapatkan kata yang sudah dibaca
char* getWord() {
    return currentWord;
}
