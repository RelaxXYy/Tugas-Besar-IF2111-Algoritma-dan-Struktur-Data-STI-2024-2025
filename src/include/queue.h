#ifndef QUEUE_H
#define QUEUE_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

typedef struct {
    int buffer[MAX_QUEUE]; 
    int head;            
    int tail;            
    int count;            
} Queue;

typedef struct {
    int buffer[MAX_QUEUE]; 
    int head;            
    int tail;            
    int count;        
} CircularQueue;

void create_queue(Queue *queue);
boolean is_queue_full(Queue *queue);
boolean is_queue_empty(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue, int *item);
int front(Queue *queue);
int rear(Queue *queue);

void create_circular_queue(CircularQueue *queue);
boolean is_circular_queue_full(CircularQueue *queue);
boolean is_circular_queue_empty(CircularQueue *queue);
void enqueue_circular(CircularQueue *queue, int item);
int dequeue_circular(CircularQueue *queue, int *item);
int front_circular(CircularQueue *queue);
int rear_circular(CircularQueue *queue);

#endif