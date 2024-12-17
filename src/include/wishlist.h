#ifndef WISHLIST_H
#define WISHLIST_H

#include "all_library_headers.h"
#include "config.h"

typedef struct
{
  int posisi;
  int nama_barang;
} Wish;

typedef struct
{
  Wish item[MAX_LIST];
  int Count;
} LinkedList;

extern Wish wish;
extern LinkedList wishlist;

void wishListShow();


void wishListClear();

#endif