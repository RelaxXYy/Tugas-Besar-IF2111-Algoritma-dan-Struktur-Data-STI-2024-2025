#ifndef BARANG_H
#define BARANG_H

#include "../Mesin_Karakter/mesin_karakter.h"
#include "../Mesin_Kata/mesin_kata.h"
#include "../../all_library_headers.h"
#include "../../boolean.h"
#include "../../config.h"

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct{
    Barang *buffer;
    int size;
    int capacity;
} ListBarang;

typedef struct {
    char name[MAX_QUEUE][MAX_LEN];
    int count;
    int tail;
    int head;
} QueueBarang;

extern ListBarang barangs;
extern QueueBarang qbarangs;

void create_list_barang(ListBarang *barangs);
int barang_count(ListBarang *barangs);
int barang_index(ListBarang *barangs, char *name);
void add_barang(ListBarang *barangs, char *name, int price);
void delete_barang(ListBarang *barangs, char *name);
boolean is_barang_exist(ListBarang *barangs, char *name);
int harga_barang(ListBarang *barangs, char *name);
void create_queue_barang(QueueBarang *qbarangs);
void enqueue_barang(QueueBarang *qbarangs, char *name);
void dequeue_barang(QueueBarang *qbarangs, char *name);
void front_barang(QueueBarang *qbarangs, char *name);
boolean is_queue_barang_full(QueueBarang *qbarangs);
boolean is_queue_barang_empty(QueueBarang *qbarangs);
boolean is_barang_exist_queue(QueueBarang *qbarangs, char *name);
void print_list_barang(ListBarang *barangs);
void print_queue_barang(QueueBarang *qbarangs);

#endif