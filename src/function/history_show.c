#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "history_show.h"

void history_show(int n)
{
	if(current_user.riwayat_pembelian.IndexTop == -1) printf("Kamu belum membeli barang apapun!\n");
	else{
		if (n > current_user.riwayat_pembelian.IndexTop + 1) n = current_user.riwayat_pembelian.IndexTop + 1;
		History temp_history = current_user.riwayat_pembelian;
		printf("Riwayat pembelian barang:\n");
		for (int i = 0; i < n; i++){
			HistoryElement temp_history_element;
			pop_history(&temp_history, &temp_history_element);
			printf("\nPembelian %d - Total: \n", i + 1, temp_history_element.TotalPrice);
			printf("Kuantitas	Barang    Total\n");
			for (int j = 0; j < temp_history_element.HistoryBarangCount; j++){
				printf("%d			%s		%d\n", temp_history_element.HistoryBarangs[j].amount, temp_history_element.HistoryBarangs[j].buffer.name, temp_history_element.HistoryBarangs[j].buffer.price * temp_history_element.HistoryBarangs[j].amount);
			}
		}
	}
	return;
}