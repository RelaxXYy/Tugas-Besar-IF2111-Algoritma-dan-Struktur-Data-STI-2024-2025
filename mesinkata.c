#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

char currentChar;
char currentWord[MAX_LEN];
int currentLength;
boolean endWord;  // Pastikan tipe data bool

// Mulai pembacaan kata
void startWord() {
    currentLength = 0;
    endWord = false;

    // Membaca karakter pertama, lewati spasi atau newline
    do {
        currentChar = getchar();
    } while (currentChar == ' ' || currentChar == '\n');

    if (currentChar == EOF) {
        endWord = true;
        currentWord[0] = '\0'; // Kosongkan currentWord
        return;
    }

    // Membaca kata sampai spasi, newline, atau EOF
    while (currentChar != ' ' && currentChar != '\n' && currentChar != EOF) {
        if (currentLength < MAX_LEN - 1) {
            currentWord[currentLength++] = currentChar;
        }
        currentChar = getchar();
    }

    currentWord[currentLength] = '\0'; // Tambahkan null terminator
    // Deteksi akhir kata
    if (currentChar == EOF || currentChar == '\n') {
        endWord = true;
    }
}

// Lanjut membaca kata berikutnya
void advanceWord() {
    startWord();
}

// Mendapatkan kata yang sudah dibaca
char* getWord() {
    return currentWord;
}
