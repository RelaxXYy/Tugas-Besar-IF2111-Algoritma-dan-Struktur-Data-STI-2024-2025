#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

Queue queue;
CircularQueue circular_queue;

void create_queue(Queue *queue) {
    (*queue).head = 0;
    (*queue).tail = 0;
    (*queue).count = 0;
}

boolean is_queue_full(Queue *queue) {
    return (*queue).count == MAX_QUEUE;
}

boolean is_queue_empty(Queue *queue) {
    return (*queue).count == 0;
}

void enqueue(Queue *queue, int item) {
    if (!is_queue_full(queue)) {
        (*queue).buffer[(*queue).tail] = item;
        (*queue).tail = ((*queue).tail + 1) % MAX_QUEUE;
        (*queue).count++;
    }
}

int dequeue(Queue *queue, int *item) {
    if (!is_queue_empty(queue)) {
        *item = (*queue).buffer[(*queue).head];
        (*queue).head = ((*queue).head + 1) % MAX_QUEUE;
        (*queue).count--;
        return *item;
    }
    return -1;
}

int front(Queue *queue) {
    if (!is_queue_empty(queue)) {
        return (*queue).buffer[(*queue).head];
    }
    return -1;
}

int rear(Queue *queue) {
    if (!is_queue_empty(queue)) {
        return (*queue).buffer[(*queue).tail - 1];
    }
    return -1;
}



void create_circular_queue(CircularQueue *queue) {
    (*queue).head = 0;
    (*queue).tail = 0;
    (*queue).count = 0;
}

boolean is_circular_queue_full(CircularQueue *queue) {
    return (*queue).count == MAX_QUEUE;
}

boolean is_circular_queue_empty(CircularQueue *queue) {
    return (*queue).count == 0;
}

void enqueue_circular(CircularQueue *queue, int item) {
    if (!is_circular_queue_full(queue)) {
        (*queue).buffer[(*queue).tail] = item;
        (*queue).tail = ((*queue).tail + 1) % MAX_QUEUE;
        (*queue).count++;
    }
}

int dequeue_circular(CircularQueue *queue, int *item) {
    if (!is_circular_queue_empty(queue)) {
        *item = (*queue).buffer[(*queue).head];
        (*queue).head = ((*queue).head + 1) % MAX_QUEUE;
        (*queue).count--;
        return *item;
    }
    return -1;
}

int front_circular(CircularQueue *queue) {
    if (!is_circular_queue_empty(queue)) {
        return (*queue).buffer[(*queue).head];
    }
    return -1;
}

int rear_circular(CircularQueue *queue) {
    if (!is_circular_queue_empty(queue)) {
        return (*queue).buffer[(*queue).tail - 1];
    }
    return -1;
}