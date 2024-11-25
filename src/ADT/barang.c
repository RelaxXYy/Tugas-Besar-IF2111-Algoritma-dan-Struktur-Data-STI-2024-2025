#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void create_list_barang(ListBarang *barangs) {
    (*barangs).buffer = (Barang*) malloc(INIT_BARANG * sizeof(Barang));
    (*barangs).size = 0;
    (*barangs).capacity = INIT_BARANG;
}

void resize_list_barang(ListBarang *barangs) {
    int new_capacity = (*barangs).capacity * 2;
    Barang *new_buffer = (Barang*) malloc(new_capacity * sizeof(Barang));
    for (int i = 0; i < (*barangs).size; i++) {
        new_buffer[i] = (*barangs).buffer[i];
    }
    free((*barangs).buffer);
    (*barangs).buffer = new_buffer;
    (*barangs).capacity = new_capacity;
}

int barang_count(ListBarang *barangs) {
    return (*barangs).size;
}

int barang_index(ListBarang *barangs, char *name) {
    int i = 0;
    while ((*barangs).buffer[i].name[0] != '\0') {
        char str1[MAX_LEN], str2[MAX_LEN];
        make_upper_string((*barangs).buffer[i].name, str1);
        make_upper_string(name, str2);
        if (is_same_string(str1, str2) == true) {
            return i;
        }
        i++;
    }
    
    return -1;
}

void add_barang(ListBarang *barangs, char *name, int price) {
    int i = barang_count(barangs);
    if(is_barang_exist(barangs, name)) {
        return;
    }
    if (i == (*barangs).capacity) {
        int new_capacity = (*barangs).capacity * 2;
        Barang *new_buffer = (Barang*) malloc(new_capacity * sizeof(Barang));
        for (int i = 0; i < (*barangs).size; i++) {
            new_buffer[i] = (*barangs).buffer[i];
        }
        free((*barangs).buffer);
        (*barangs).buffer = new_buffer;
        (*barangs).capacity = new_capacity;
        }
    copy_string(name, (*barangs).buffer[i].name);
    (*barangs).buffer[i].price = price;
    (*barangs).size++;
}

void delete_barang(ListBarang *barangs, char *name) {
    int index = barang_index(barangs, name);
    if (index != -1) {
        for (int i = index; i < (*barangs).size - 1; i++) {
            copy_string((*barangs).buffer[i + 1].name, (*barangs).buffer[i].name);
            (*barangs).buffer[i].price = (*barangs).buffer[i + 1].price;
        }
        (*barangs).size--;
    }
}

boolean is_barang_exist(ListBarang *barangs, char *name) {
    return barang_index(barangs, name) != -1;
}

void create_queue_barang(QueueBarang *qbarangs) {
    (*qbarangs).head = -1;
    (*qbarangs).tail = -1;
    (*qbarangs).count = 0;
}

boolean is_queue_barang_full(QueueBarang *qbarangs) {
    return (*qbarangs).count == MAX_QUEUE;
}

boolean is_queue_barang_empty(QueueBarang *qbarangs) {
    return (*qbarangs).count == 0;
}

void enqueue_barang(QueueBarang *qbarangs, char *name) {
    if ((*qbarangs).count < MAX_QUEUE) {
        if(is_queue_barang_empty(qbarangs)) {
            (*qbarangs).head = 0;
            (*qbarangs).tail = 0;
        }
        else {
            (*qbarangs).tail = ((*qbarangs).tail + 1) % MAX_QUEUE;
        }
        copy_string(name, (*qbarangs).name[(*qbarangs).tail]);
        (*qbarangs).count++;
    } else {
        printf("Queue barang penuh.\n");
    }
}

void dequeue_barang(QueueBarang *qbarangs, char *name) {
    if ((*qbarangs).count > 0) {
        copy_string((*qbarangs).name[(*qbarangs).head], name);
        if((*qbarangs).count == 1) {
            (*qbarangs).head = -1;
            (*qbarangs).tail = -1;
        } else {
            (*qbarangs).head = ((*qbarangs).head + 1) % MAX_QUEUE;
        }
        (*qbarangs).count--;
    } else {
        printf("Queue barang kosong\n");
        copy_string("", name);
    }
}

void front_barang(QueueBarang *qbarangs, char *name) {
    if ((*qbarangs).count > 0) {
        copy_string((*qbarangs).name[(*qbarangs).head], name);
    } else {
        printf("Queue barang kosong.\n");
        copy_string("", name);
    }
}

boolean is_barang_exist_queue(QueueBarang *qbarangs, char *name) {
    for (int i = 0; i < (*qbarangs).count; i++) {
        char str1[MAX_LEN], str2[MAX_LEN];
        make_upper_string((*qbarangs).name[i], str1);
        make_upper_string(name, str2);
        if (is_same_string(str1, str2) == true) {
            return true;
        }
    }
    return false;
}

void print_list_barang(ListBarang *barangs) {
    printf("List of Barang:\n");
    for (int index = 0; index < barangs->size; index++) {
        printf("Name: %s, Price: %d\n", barangs->buffer[index].name, barangs->buffer[index].price);
    }
}

void print_queue_barang(QueueBarang *qbarangs) {
    printf("Queue of Barang:\n");
    for (int i = 0; i < qbarangs->count; i++) {
        int index = (qbarangs->head + i) % MAX_QUEUE;
        printf("Name: %s\n", qbarangs->name[index]);
    }
}