#ifndef MESINKATA_H
#define MESINKATA_H
#include "boolean.h"  // Meng-include boolean.h untuk mendefinisikan boolean, true, false

#define NMax 100

extern char currentChar;
extern char currentWord[NMax + 1];
extern boolean endWord;

void advChar();      // Membaca karakter berikutnya
void startWord();    // Memulai pembacaan kata
void copyWord();     // Opsional: Untuk menyalin kata jika diperlukan

#endif
