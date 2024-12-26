#include "history.h"

void create_history(History *history) {
    history->IndexTop = -1;
}

void push_history(History *history, HistoryElement historyElement) {
    if (history->IndexTop < MAX_STACK - 1) {
        history->IndexTop++;
        history->HistoryElements[history->IndexTop] = historyElement;
    } else {
        printf("History penuh.\n");
    }
}

void pop_history(History *history, HistoryElement *historyElement) {
    if (history->IndexTop >= 0) {
        *historyElement = history->HistoryElements[history->IndexTop];
        history->IndexTop--;
    } else {
        printf("History kosong.\n");
    }
}