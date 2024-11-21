#ifndef MESINKATA_H
#define MESINKATA_H

#include "all_ADT_headers.h"
#include "boolean.h"
#include "config.h"

#define BLANK ' '

typedef struct {
    char tab_word[NMax];
    int length;
} Word;

extern boolean end_word;
extern Word current_word;

void ignore_blank();
void start_word();
void adv_word();
void copy_word();
boolean is_same_word(Word w1, Word w2);
Word string_to_word(char *str);
void print_word(Word w);
void copy_string(char *to, char *from);
boolean is_same_string(char *str1, char *str2);

#endif