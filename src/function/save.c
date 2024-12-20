#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"

// NOTES
// line 33 = print jumlah riwayat pembelian
// line 34 = print semua nama barang dan harga di riwayat pembelian bagi setiap user
// line 39 = print jumlah wishlist (wishlist_count ngawang)
// line 41--45 = print nama semua wishlist bagi setiap user

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
            for (int i = 0; i < users.buffer[i].riwayat_pembelian.IndexTop; i++) {
                printf("%d %d\n", users.buffer[i].riwayat_pembelian.HistoryElements[i].HistoryBarangs->buffer.name, users.buffer[i].riwayat_pembelian.HistoryElements[i].HistoryBarangs->amount);
                for (int j = 0; j < users.buffer[i].riwayat_pembelian.HistoryElements[i].HistoryBarangCount; j++) {
                    fprintf(file, "- %s %d\n", users.buffer[i].riwayat_pembelian.HistoryElements[i].HistoryBarangs[j].buffer.name, users.buffer[i].riwayat_pembelian.HistoryElements[i].HistoryBarangs[j].amount);
                }
            }           
        }

        fprintf(file, "%d\n", count_wishlist(&users.buffer[i].wishlist));
        if (count_wishlist(&users.buffer[i].wishlist) != 0) {
            Address P = users.buffer[i].wishlist.First;
            while (P != NULL) {
                printf("%d\n", P->Nama);
                P = P->Next;
            } 
        }
    }    

    fclose(file);
    printf("Save file berhasil disimpan. save berhasil.\n");
}