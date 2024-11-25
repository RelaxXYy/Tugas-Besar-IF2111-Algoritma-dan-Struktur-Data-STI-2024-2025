#ifndef LIST_H
#define LIST_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"


typedef struct {
    int buffer[MAX_LIST]; 
    int count;           
} StaticIntList;

void create_static_int_list(StaticIntList *list);
boolean is_static_int_list_full(StaticIntList *list);
boolean is_static_int_list_empty(StaticIntList *list);
boolean is_static_int_list_exist(StaticIntList *list, int value);
int index_static_int_list(StaticIntList *list, int value);
void insert_static_int_list(StaticIntList *list, int value);
void delete_static_int_list(StaticIntList *list, int value);

typedef struct {
    int *buffer;    
    int size;     
    int capacity; 
} DynamicIntList;

void create_dynamic_int_list(DynamicIntList *list, int capacity);
void free_dynamic_int_list(DynamicIntList *list);
void resize_dynamic_int_list(DynamicIntList *list);
boolean is_dynamic_int_list_full(DynamicIntList *list);
boolean is_dynamic_int_list_empty(DynamicIntList *list);
boolean is_dynamic_int_list_exist(DynamicIntList *list, int value);
int index_dynamic_int_list(DynamicIntList *list, int value);
void insert_dynamic_int_list(DynamicIntList *list, int value);
void delete_dynamic_int_list(DynamicIntList *list, int value);

typedef struct {
    char buffer[MAX_LIST]; 
    int count;             
} StaticCharList;

void create_static_char_list(StaticCharList *list);
boolean is_static_char_list_full(StaticCharList *list);
boolean is_static_char_list_empty(StaticCharList *list);
boolean is_static_char_list_exist(StaticCharList *list, char value);
int index_static_char_list(StaticCharList *list, char value);
void insert_static_char_list(StaticCharList *list, char value);
void delete_static_char_list(StaticCharList *list, char value);


typedef struct {
    char *buffer;    
    int size;      
    int capacity;  
} DynamicCharList;

void create_dynamic_char_list(DynamicCharList *list, int capacity);
void free_dynamic_char_list(DynamicCharList *list);
void resize_dynamic_char_list(DynamicCharList *list);
boolean is_dynamic_char_list_full(DynamicCharList *list);
boolean is_dynamic_char_list_empty(DynamicCharList *list);
boolean is_dynamic_char_list_exist(DynamicCharList *list, char value);
int index_dynamic_char_list(DynamicCharList *list, char value);
void insert_dynamic_char_list(DynamicCharList *list, char value);
void delete_dynamic_char_list(DynamicCharList *list, char value);

#endif