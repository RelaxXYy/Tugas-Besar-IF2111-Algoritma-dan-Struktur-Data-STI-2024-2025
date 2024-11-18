#include <stdio.h>
#include <stdbool.h>  // Pastikan include ini ada
#include "mesinkata.h"

#define MAX_LEN 256

char currentChar;
char currentWord[MAX_LEN];
int currentLength;
bool endWord;  // Pastikan tipe data bool

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
}

// Lanjut membaca kata berikutnya
void advanceWord() {
    currentLength = 0;

    while (currentChar != ' ' && currentChar != '\n' && currentChar != EOF) {
        if (currentLength < MAX_LEN - 1) {
            currentWord[currentLength] = currentChar; // Tambahkan ke kata
            currentLength++;
        }
        currentChar = getchar(); // Baca karakter berikutnya
    }
    currentWord[currentLength] = '\0'; // Tambahkan null terminator

    while (currentChar == ' ' || currentChar == '\n') {
        currentChar = getchar(); // Lewati spasi atau newline
    }

    if (currentChar == EOF) {
        endWord = true;
    }
}

// Mendapatkan kata yang sudah dibaca
char* getWord() {
    return currentWord;
}
