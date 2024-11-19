#ifndef MESINKATA_H
#define MESINKATA_H

#define NMax 100
typedef int boolean;
#define true 1
#define false 0

extern char currentChar;
extern char currentWord[NMax + 1];
extern boolean endWord;

void advChar();      // Membaca karakter berikutnya
void startWord();    // Memulai pembacaan kata
void copyWord();     // Opsional: Untuk menyalin kata jika diperlukan

#endif
