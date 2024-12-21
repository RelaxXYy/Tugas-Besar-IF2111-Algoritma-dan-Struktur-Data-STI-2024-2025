#ifndef WORK_H
#define WORK_H

#include "../all_library_headers.h"
#include "../boolean.h"
#include "../config.h"

typedef struct {
    char name[MAX_LEN];
    int income;
    int duration;
} Job;

void wait_time(int seconds);
void handle_work();

#endif