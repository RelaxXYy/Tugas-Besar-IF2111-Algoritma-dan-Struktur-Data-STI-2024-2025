#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

StaticIntList static_int_list;
StaticCharList static_char_list;
DynamicIntList dynamic_int_list;
DynamicCharList dynamic_char_list;

void create_static_int_list(StaticIntList *list) {
    (*list).count = 0;
}

boolean is_static_int_list_full(const StaticIntList *list) {
    return (*list).count == MAX_LIST;
}

boolean is_static_int_list_empty(const StaticIntList *list) {
    return (*list).count == 0;
}

boolean is_static_int_list_exist(const StaticIntList *list, int value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_static_int_list(const StaticIntList *list, int value) {
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



void create_dynamic_int_list(DynamicIntList *list, int capacity) {
    (*list).data = (int*) malloc(capacity * sizeof(int));
    (*list).size = 0;
    (*list).capacity = capacity;
}

void free_dynamic_int_list(DynamicIntList *list) {
    free((*list).data);
    (*list).size = 0;
    (*list).capacity = 0;
}

void resize_dynamic_int_list(DynamicIntList *list) {
    int new_capacity = (*list).capacity * 2;
    int *new_data = (int*) malloc(new_capacity * sizeof(int));
    for (int i = 0; i < (*list).size; i++) {
        new_data[i] = (*list).data[i];
    }
    free((*list).data);
    (*list).data = new_data;
    (*list).capacity = new_capacity;
}

boolean is_dynamic_int_list_full(const DynamicIntList *list) {
    return (*list).size == (*list).capacity;
}

boolean is_dynamic_int_list_empty(const DynamicIntList *list) {
    return (*list).size == 0;
}

boolean is_dynamic_int_list_exist(const DynamicIntList *list, int value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).data[i] == value) return true;
    }
    return false;
}

int index_dynamic_int_list(const DynamicIntList *list, int value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).data[i] == value) return i;
    }
    return -1;
}

void insert_dynamic_int_list(DynamicIntList *list, int value) {
    if (is_dynamic_int_list_full(list)) {
        resize_dynamic_int_list(list);
    }
    (*list).data[(*list).size] = value;
    (*list).size++;
}

void delete_dynamic_int_list(DynamicIntList *list, int value) {
    int index = index_dynamic_int_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).size - 1; i++) {
            (*list).data[i] = (*list).data[i + 1];
        }
        (*list).size--;
    }
}



void create_static_char_list(StaticCharList *list) {
    (*list).count = 0;
}

boolean is_static_char_list_full(const StaticCharList *list) {
    return (*list).count == MAX_LIST;
}

boolean is_static_char_list_empty(const StaticCharList *list) {
    return (*list).count == 0;
}

boolean is_static_char_list_exist(const StaticCharList *list, char value) {
    for (int i = 0; i < (*list).count; i++) {
        if ((*list).buffer[i] == value) return true;
    }
    return false;
}

int index_static_char_list(const StaticCharList *list, char value) {
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



void create_dynamic_char_list(DynamicCharList *list, int capacity) {
    (*list).data = (char*) malloc(capacity * sizeof(char));
    (*list).size = 0;
    (*list).capacity = capacity;
}

void free_dynamic_char_list(DynamicCharList *list) {
    free((*list).data);
    (*list).size = 0;
    (*list).capacity = 0;
}

void resize_dynamic_char_list(DynamicCharList *list) {
    int new_capacity = (*list).capacity * 2;
    char *new_data = (char*) malloc(new_capacity * sizeof(char));
    for (int i = 0; i < (*list).size; i++) {
        new_data[i] = (*list).data[i];
    }
    free((*list).data);
    (*list).data = new_data;
    (*list).capacity = new_capacity;
}

boolean is_dynamic_char_list_full(const DynamicCharList *list) {
    return (*list).size == (*list).capacity;
}

boolean is_dynamic_char_list_empty(const DynamicCharList *list) {
    return (*list).size == 0;
}

boolean is_dynamic_char_list_exist(const DynamicCharList *list, char value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).data[i] == value) return true;
    }
    return false;
}

int index_dynamic_char_list(const DynamicCharList *list, char value) {
    for (int i = 0; i < (*list).size; i++) {
        if ((*list).data[i] == value) return i;
    }
    return -1;
}

void insert_dynamic_char_list(DynamicCharList *list, char value) {
    if (is_dynamic_char_list_full(list)) {
        resize_dynamic_char_list(list);
    }
    (*list).data[(*list).size] = value;
    (*list).size++;
}

void delete_dynamic_char_list(DynamicCharList *list, char value) {
    int index = index_dynamic_char_list(list, value);
    if (index != -1) {
        for (int i = index; i < (*list).size - 1; i++) {
            (*list).data[i] = (*list).data[i + 1];
        }
        (*list).size--;
    }
}