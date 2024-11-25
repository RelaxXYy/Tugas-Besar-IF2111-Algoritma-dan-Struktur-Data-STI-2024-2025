#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"
#include <stdio.h>

extern void start(char *filename);
extern void adv();
extern void adv_word();
extern void start_word();
extern char get_current_char();
extern boolean is_eop();
extern boolean end_word;
extern Word current_word;
extern void print_word(Word w);

extern void create_queue(Queue *queue);
extern boolean is_queue_full(Queue *queue);
extern boolean is_queue_empty(Queue *queue);
extern void enqueue(Queue *queue, int item);
extern int dequeue(Queue *queue, int *item);
extern int front(Queue *queue);
extern int rear(Queue *queue);

extern void create_circular_queue(CircularQueue *queue);
extern boolean is_circular_queue_full(CircularQueue *queue);
extern boolean is_circular_queue_empty(CircularQueue *queue);
extern void enqueue_circular(CircularQueue *queue, int item);
extern int dequeue_circular(CircularQueue *queue, int *item);
extern int front_circular(CircularQueue *queue);
extern int rear_circular(CircularQueue *queue);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    start_word();
    if (end_word) {
        printf("File tidak bisa dibaca atau kosong.\n");
        return 1;
    }

    printf("Isi file kata per kata: \n");
    while (!end_word) {
        print_word(current_word);
        printf(" ");
        adv_word();
    }
    printf("\n");

    Queue queue;
    create_queue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    int item;
    dequeue(&queue, &item);
    printf("Dequeued item from queue: %d\n", item);

    CircularQueue circular_queue;
    create_circular_queue(&circular_queue);
    enqueue_circular(&circular_queue, 40);
    enqueue_circular(&circular_queue, 50);
    enqueue_circular(&circular_queue, 60);
    dequeue_circular(&circular_queue, &item);
    printf("Dequeued item from circular queue: %d\n", item);

    return 0;
}