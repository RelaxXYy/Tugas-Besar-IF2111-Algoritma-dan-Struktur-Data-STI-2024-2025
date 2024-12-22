#include <stdio.h>
#include "history.h"

int main() {
    History history;
    HistoryElement historyElement;

    create_history(&history);

    historyElement.TotalPrice = 0;
    historyElement.HistoryBarangCount = 0;

    printf("History telah dibuat dengan IndexTop: %d\n", history.IndexTop);

    Barang AWM = {"AWM", 10000};
    Barang KAR49 = {"KAR49", 20000};
    Barang M4 = {"M4", 15000};

    add_history_element(&historyElement, AWM, 1);
    add_history_element(&historyElement, KAR49, 2);
    add_history_element(&historyElement, M4, 3);

    printf("HistoryElement telah diisi dengan TotalPrice: %d\n", historyElement.TotalPrice);

    push_history(&history, historyElement);
    printf("HistoryElement telah di-push ke history dengan IndexTop: %d\n", history.IndexTop);

    HistoryElement poppedHistoryElement;
    pop_history(&history, &poppedHistoryElement);

    printf("HistoryElement teratas telah di-pop dengan TotalPrice: %d\n", poppedHistoryElement.TotalPrice);

    return 0;
}