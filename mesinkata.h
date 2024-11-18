#ifndef MESINKATA_H
#define MESINKATA_H

#include <stdbool.h>  // Pastikan include ini ada

extern char currentWord[256];
extern char currentChar;
extern int currentLength;
extern bool endWord;  // Pastikan tipe data bool

void startWord();
void advanceWord();
char* getWord();

#endif
