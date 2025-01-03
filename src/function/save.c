#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "save.h"

void save(char *filename) {
    char file_path[MAX_LEN], default_path[MAX_LEN] = "save/";
    concat_string(default_path, filename, file_path);
    FILE *file = fopen(file_path, "w+");
    
    if(file == NULL) {
        printf("Save file tidak ditemukan. save gagal.\n");
        eop = true;
        return;
    }

    fprintf(file, "%d\n", barang_count(&barangs));
    for (int i = 0; i < barang_count(&barangs); i++) {
        fprintf(file, "%d %s\n", barangs.buffer[i].price, barangs.buffer[i].name);
    }

    fprintf(file, "%d\n", user_count(&users));
    for (int i = 0; i < user_count(&users); i++) {

        fprintf(file, "%d %s %s\n", users.buffer[i].money, users.buffer[i].name, users.buffer[i].password);

        fprintf(file, "%d\n", users.buffer[i].riwayat_pembelian.IndexTop + 1);
        if ((users.buffer[i].riwayat_pembelian.IndexTop + 1) != 0) {
            for (int j = 0; j < users.buffer[i].riwayat_pembelian.IndexTop + 1; j++) {
                fprintf(file, "%d %d\n", users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangCount, users.buffer[i].riwayat_pembelian.HistoryElements[j].TotalPrice);
                for (int k = 0; k < users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangCount; k++) {
                    fprintf(file, "%d %d %s\n", users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangs[k].buffer.price * users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangs[k].amount, users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangs[k].amount, users.buffer[i].riwayat_pembelian.HistoryElements[j].HistoryBarangs[k].buffer.name);
                }
            }           
        }

        fprintf(file, "%d\n", count_wishlist(&users.buffer[i].wishlist));
        if (count_wishlist(&users.buffer[i].wishlist) != 0) {
            Address P = users.buffer[i].wishlist.First;
            while (P != NULL) {
                fprintf(file, "%s\n", P->Nama);
                P = P->Next;
            } 
        }
    }    

    fclose(file);
    printf("Save file berhasil disimpan. save berhasil.\n");
}