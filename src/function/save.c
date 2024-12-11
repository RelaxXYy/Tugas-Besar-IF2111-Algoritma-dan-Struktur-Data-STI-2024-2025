#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "../include/all_ADT_headers.h"

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
    }
    fclose(file);
    printf("Save file berhasil disimpan. save berhasil.\n");

}
