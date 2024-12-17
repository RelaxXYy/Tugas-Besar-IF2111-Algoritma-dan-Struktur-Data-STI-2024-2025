#ifndef CART_H
#define CART_H

#include "all_library_headers.h"
#include "config.h"

typedef struct
{
  char Key[MAX_LEN];
  int Value;
} Element;

typedef struct
{
  Element Elements[MAX_LIST];
  int Count;
} Map;

extern Element element;
extern Map keranjang;

void cartShow();

int getHargaByNama(char *name);

char intToStr(int num, char str[]);

#endif