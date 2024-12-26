#ifndef HISTORY_H
#define HISTORY_H

#include "../Barang/barang.h"
#include "../../config.h"
#include "../../boolean.h"

typedef struct {
    Barang buffer;
    int amount;
} HistoryBarang;

typedef struct {
    HistoryBarang HistoryBarangs[MAX_LIST];
    int HistoryBarangCount;
    int TotalPrice;
} HistoryElement;

typedef struct {
    HistoryElement HistoryElements[MAX_STACK];
    int IndexTop;
} History;

void create_history(History *history);
void push_history(History *history, HistoryElement historyElement);
void pop_history(History *history, HistoryElement *historyElement);

#endif