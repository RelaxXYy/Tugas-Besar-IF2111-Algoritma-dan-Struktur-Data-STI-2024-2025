#include "history.h"

void create_history(History *history) {
    history->IndexTop = -1;
}

void add_history_element(HistoryElement *historyElement, Barang barang, int amount) {
    historyElement->HistoryBarangs[historyElement->HistoryBarangCount].buffer = barang;
    historyElement->HistoryBarangs[historyElement->HistoryBarangCount].amount = amount;
    historyElement->TotalPrice += barang.price * amount;
    historyElement->HistoryBarangCount++;
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