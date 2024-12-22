#include "mesin_kata.h"

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
        adv_line();
        i++;
    }
    current_word.tab_word[i] = '\0';
    current_word.length = i;
}

void get_first_word(char* str, char* first_word){
    int i = 0;
    while(str[i] != ' ' && str[i] != NN && str[i] != '\0'){
        i++;
    }
    for(int j = 0; j < i; j++){
        first_word[j] = str[j];
    }
    first_word[i] = '\0';
}

void ignore_first_word(char* str, char* new_str){
    int i = 0;
    while(str[i] != ' ' && str[i] != NN && str[i] != '\0'){
        i++;
    }
    i++;
    int j = 0;
    while(str[i] != '\0'){
        new_str[j] = str[i];
        i++;
        j++;
    }
    new_str[j] = '\0';
}

void concat_string(char* str1, char* str2, char* result){
    int i = 0;
    while(str1[i] != '\0'){
        result[i] = str1[i];
        i++;
    }
    int j = 0;
    while(str2[j] != '\0'){
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

void make_upper_string(char* from, char* to){
    int i = 0;
    while(from[i] != '\0'){
        if(from[i] >= 'a' && from[i] <= 'z'){
            to[i] = from[i] - 'a' + 'A';
        } else {
            to[i] = from[i];
        }
        i++;
    }
    to[i] = '\0';
}

boolean is_blank_exist(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            return true;
        }
        i++;
    }
    return false;
}

boolean is_letter_or_digit(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')){
            return false;
        }
        i++;
    }
    return true;
}

boolean is_letter(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')){
            return false;
        }
        i++;
    }
    return true;
}

boolean is_digit(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] < '0' || str[i] > '9'){
            return false;
        }
        i++;
    }
    return true;
}

boolean validate_input(char* str){
    int i = 0;
    if (str[0] == '\0') {
        return false;
    }
    while(str[i] != '\0'){
        if(str[i] != ' '){
            return true;
        }
        i++;
    }
    return false;
}

void delete_newline(char *from, char *to){
    int i = 0;
    while(from[i] != '\0'){
        if(from[i] == NN){
            to[i] = '\0';
            return;
        }
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

void int_to_string(int number, char *str) {
    int i = 0;
    while(number > 0) {
        str[i] = number % 10 + '0';
        number /= 10;
        i++;
    }
    str[i] = '\0';
}

void string_to_int(char *str, int *number) {
    *number = 0;
    int i = 0;
    while(str[i] != '\0') {
        *number = *number * 10 + (str[i] - '0');
        i++;
    }
}

int string_length(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void clear_input_buffer(){
    while (get_current_char() != '\n' &&  !EOF );
}

int get_positive_integer(){
    int i = 0, x = 0;
    clear_input_buffer();
    get_line();
    while(current_word.tab_word[i] != '\0'){
        if(current_word.tab_word[i] < '0' || current_word.tab_word[i] > '9') return -1;
        x = x * 10 + (current_word.tab_word[i] - '0');
        i++;    
    }
    return x;
}

void clear_string(char* str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = '\0';
        i++;
    }
}

void get_last_word(char* str, char* last_word){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    i--;
    while(i >= 0 && str[i] != ' '){
        i--;
    }
    i++;
    int j = 0;
    while(str[i] != '\0'){
        last_word[j] = str[i];
        i++;
        j++;
    }
    last_word[j] = '\0';
}

void ignore_last_word(char* str, char* new_str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0 && str[i] != ' ') {
        i--;
    }
    int j = 0;
    for (int k = 0; k < i; k++) {
        new_str[j] = str[k];
        j++;
    }
    new_str[j] = '\0';
}