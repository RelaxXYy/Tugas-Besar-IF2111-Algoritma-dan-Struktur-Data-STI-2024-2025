#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void create_static_int_list(StaticIntList *list) {
    (*list).count = 0;
}

boolean is_static_int_list_full(StaticIntList *list) {
    return (*list).count == MAX_LIST;
}

boolean is_static_int_list_empty(StaticIntList *list) {
    return (*list).count == 0;
}

boolean is_static_int_list_exist(StaticIntList *list, int value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_static_int_list(StaticIntList *list, int value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return i;
    }
    return -1;
}

void insert_static_int_list(StaticIntList *list, int value) {
    if (!is_static_int_list_full(list)) {
        (*list).buffer[(*list).count] = value;
        (*list).count++;
    }
}

void delete_static_int_list(StaticIntList *list, int value) {
    int index = index_static_int_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).count - 1; i++) {
            (*list).buffer[i] = (*list).buffer[i + 1];
        }
        (*list).count--;
    }
}

void create_static_char_list(StaticCharList *list) {
    (*list).count = 0;
}

boolean is_static_char_list_full(StaticCharList *list) {
    return (*list).count == MAX_LIST;
}

boolean is_static_char_list_empty(StaticCharList *list) {
    return (*list).count == 0;
}

boolean is_static_char_list_exist(StaticCharList *list, char value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_static_char_list(StaticCharList *list, char value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return i;
    }
    return -1;
}

void insert_static_char_list(StaticCharList *list, char value) {
    if (!is_static_char_list_full(list)) {
        (*list).buffer[(*list).count] = value;
        (*list).count++;
    }
}

void delete_static_char_list(StaticCharList *list, char value) {
    int index = index_static_char_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).count - 1; i++) {
            (*list).buffer[i] = (*list).buffer[i + 1];
        }
        (*list).count--;
    }
}
