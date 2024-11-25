#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

DynamicIntList dynamic_int_list;
DynamicCharList dynamic_char_list;

void create_dynamic_int_list(DynamicIntList *list, int capacity) {
    (*list).buffer = (int*) malloc(capacity * sizeof(int));
    (*list).size = 0;
    (*list).capacity = capacity;
}

void free_dynamic_int_list(DynamicIntList *list) {
    free((*list).buffer);
    (*list).size = 0;
    (*list).capacity = 0;
}

void resize_dynamic_int_list(DynamicIntList *list) {
    int new_capacity = (*list).capacity * 2;
    int *new_buffer = (int*) malloc(new_capacity * sizeof(int));
    for (int i = 0; i < (*list).size; i++) {
        new_buffer[i] = (*list).buffer[i];
    }
    free((*list).buffer);
    (*list).buffer = new_buffer;
    (*list).capacity = new_capacity;
}

boolean is_dynamic_int_list_full(DynamicIntList *list) {
    return (*list).size == (*list).capacity;
}

boolean is_dynamic_int_list_empty(DynamicIntList *list) {
    return (*list).size == 0;
}

boolean is_dynamic_int_list_exist(DynamicIntList *list, int value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_dynamic_int_list(DynamicIntList *list, int value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).buffer[i] == value) return i;
    }
    return -1;
}

void insert_dynamic_int_list(DynamicIntList *list, int value) {
    if (is_dynamic_int_list_full(list)) {
        resize_dynamic_int_list(list);
    }
    (*list).buffer[(*list).size] = value;
    (*list).size++;
}

void delete_dynamic_int_list(DynamicIntList *list, int value) {
    int index = index_dynamic_int_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).size - 1; i++) {
            (*list).buffer[i] = (*list).buffer[i + 1];
        }
        (*list).size--;
    }
}

void create_dynamic_char_list(DynamicCharList *list, int capacity) {
    (*list).buffer = (char*) malloc(capacity * sizeof(char));
    (*list).size = 0;
    (*list).capacity = capacity;
}

void free_dynamic_char_list(DynamicCharList *list) {
    free((*list).buffer);
    (*list).size = 0;
    (*list).capacity = 0;
}

void resize_dynamic_char_list(DynamicCharList *list) {
    int new_capacity = (*list).capacity * 2;
    char *new_buffer = (char*) malloc(new_capacity * sizeof(char));
    for (int i = 0; i < (*list).size; i++) {
        new_buffer[i] = (*list).buffer[i];
    }
    free((*list).buffer);
    (*list).buffer = new_buffer;
    (*list).capacity = new_capacity;
}

boolean is_dynamic_char_list_full(DynamicCharList *list) {
    return (*list).size == (*list).capacity;
}

boolean is_dynamic_char_list_empty(DynamicCharList *list) {
    return (*list).size == 0;
}

boolean is_dynamic_char_list_exist(DynamicCharList *list, char value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_dynamic_char_list(DynamicCharList *list, char value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).buffer[i] == value) return i;
    }
    return -1;
}

void insert_dynamic_char_list(DynamicCharList *list, char value) {
    if (is_dynamic_char_list_full(list)) {
        resize_dynamic_char_list(list);
    }
    (*list).buffer[(*list).size] = value;
    (*list).size++;
}

void delete_dynamic_char_list(DynamicCharList *list, char value) {
    int index = index_dynamic_char_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).size - 1; i++) {
            (*list).buffer[i] = (*list).buffer[i + 1];
        }
        (*list).size--;
    }
}
