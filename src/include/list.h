#ifndef LIST_H
#define LIST_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

// Static list of integers
typedef struct {
    int buffer[MAX_LIST]; // Array to store the elements
    int count;            // Number of elements in the list
} StaticIntList;

// Function prototypes for StaticIntList
void create_static_int_list(StaticIntList *list);
boolean is_static_int_list_full(const StaticIntList *list);
boolean is_static_int_list_empty(const StaticIntList *list);
boolean is_static_int_list_exist(const StaticIntList *list, int value);
int index_static_int_list(const StaticIntList *list, int value);
void insert_static_int_list(StaticIntList *list, int value);
void delete_static_int_list(StaticIntList *list, int value);

// Dynamic list of integers
typedef struct {
    int *data;    // Pointer to dynamically allocated array
    int size;     // Current number of elements in the list
    int capacity; // Maximum capacity of the list
} DynamicIntList;

// Function prototypes for DynamicIntList
void create_dynamic_int_list(DynamicIntList *list, int capacity);
void free_dynamic_int_list(DynamicIntList *list);
void resize_dynamic_int_list(DynamicIntList *list);
boolean is_dynamic_int_list_full(const DynamicIntList *list);
boolean is_dynamic_int_list_empty(const DynamicIntList *list);
boolean is_dynamic_int_list_exist(const DynamicIntList *list, int value);
int index_dynamic_int_list(const DynamicIntList *list, int value);
void insert_dynamic_int_list(DynamicIntList *list, int value);
void delete_dynamic_int_list(DynamicIntList *list, int value);

// Static list of characters
typedef struct {
    char buffer[MAX_LIST]; // Array to store the elements
    int count;             // Number of elements in the list
} StaticCharList;

// Function prototypes for StaticCharList
void create_static_char_list(StaticCharList *list);
boolean is_static_char_list_full(const StaticCharList *list);
boolean is_static_char_list_empty(const StaticCharList *list);
boolean is_static_char_list_exist(const StaticCharList *list, char value);
int index_static_char_list(const StaticCharList *list, char value);
void insert_static_char_list(StaticCharList *list, char value);
void delete_static_char_list(StaticCharList *list, char value);

// Dynamic list of characters
typedef struct {
    char *data;    // Pointer to dynamically allocated array
    int size;      // Current number of elements in the list
    int capacity;  // Maximum capacity of the list
} DynamicCharList;

// Function prototypes for DynamicCharList
void create_dynamic_char_list(DynamicCharList *list, int capacity);
void free_dynamic_char_list(DynamicCharList *list);
void resize_dynamic_char_list(DynamicCharList *list);
boolean is_dynamic_char_list_full(const DynamicCharList *list);
boolean is_dynamic_char_list_empty(const DynamicCharList *list);
boolean is_dynamic_char_list_exist(const DynamicCharList *list, char value);
int index_dynamic_char_list(const DynamicCharList *list, char value);
void insert_dynamic_char_list(DynamicCharList *list, char value);
void delete_dynamic_char_list(DynamicCharList *list, char value);

#endif