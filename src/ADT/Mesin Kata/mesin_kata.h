#ifndef MESINKATA_H
#define MESINKATA_H

#include "../all_ADT_headers.h"
#include "../../boolean.h"
#include "../../config.h"

#define BLANK ' '
#define NN '\n'

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
char* word_to_string(Word w);
void lower_string(char *str);
void upper_string(char *str);
void get_line();
void get_first_word(char *str, char *first_word);
void ignore_first_word(char *str, char *new_str);
void concat_string(char *str1, char *str2, char *result);
void make_upper_string(char *from, char *to);
boolean is_blank_exist(char *str);
boolean is_letter_or_digit(char *str);
boolean validate_input(char *str);
void delete_char(char *from, char *to);
void int_to_string(int number, char *str);
int string_length(char *str);
void clear_input_buffer();
int get_positive_integer();
void clear_string(char* str);

#endif
