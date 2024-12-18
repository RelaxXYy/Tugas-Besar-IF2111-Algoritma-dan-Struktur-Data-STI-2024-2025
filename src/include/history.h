#ifndef HISTORY_H
#define HISTORY_H

#include "all_library_headers.h"
#include "config.h"
#include "cart.h"

typedef struct
{
  Element Elements[MAX_LEN];
  int IndexTop;
} Stack;

extern Stack riwayat_pembelian;

void history(char *jumlah);
int isInteger(char *str);
int strToInt(char *str);
#endif