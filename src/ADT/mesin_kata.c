#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"

boolean end_word;
Word current_word;

void ignore_blank() {
    while (get_current_char() == BLANK && get_current_char() == NN && !is_eop()) {
        adv();
    }
}

void start_word() {
    start(NULL);
    ignore_blank();
    if (eop) {
        end_word = true;
    } else {
        end_word = false;
        copy_word();
    }
}

void adv_word() {
    ignore_blank();
    if (eop) {
        end_word = true;
    } else {
        copy_word();
    }
}

void copy_word() {
    int i = 0;
    while (get_current_char() != BLANK && get_current_char() != NN && !eop && i < NMax) {
        current_word.tab_word[i] = get_current_char();
        i++;
        adv();
    }
    current_word.length = i;
    current_word.tab_word[i] = '\0';
}

boolean is_same_word(Word w1, Word w2) {
    if (w1.length != w2.length) {
        return false;
    }
    for (int i = 0; i < w1.length; i++) {
        if (w1.tab_word[i] != w2.tab_word[i]) {
            return false;
        }
    }
    return true;
}

Word string_to_word(char *str) {
    Word w;
    int i = 0;
    while (str[i] != '\0' && i < NMax) {
        w.tab_word[i] = str[i];
        i++;
    }
    w.length = i;
    w.tab_word[i] = '\0';
    return w;
}

void print_word(Word w) {
    for (int i = 0; i < w.length; i++) {
        printf("%c", w.tab_word[i]);
    }
}

void copy_string(char *from, char *to) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

boolean is_same_string(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

char* word_to_string(Word w) {
    char *str = (char *)malloc((w.length + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < w.length; i++) {
        str[i] = w.tab_word[i];
    }
    str[w.length] = '\0';
    return str;
}

void lower_string(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
}

void upper_string(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
}

void get_line(){
    int i = 0;
    start(NULL);
    while(get_current_char() != NN){
        current_word.tab_word[i] = get_current_char();
        adv_command();
        i++;
    }
    current_word.tab_word[i] = '\0';
    current_word.length = i;
}
