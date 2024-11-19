#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"  // Menggunakan boolean dari file boolean.h
#define MAX_LEN 256

extern char currentWord[MAX_LEN];
extern char currentChar;
extern int currentLength;
extern boolean endWord;  // Tipe data boolean, bukan bool

void startWord();
void advanceWord();
char* getWord();

#endif
