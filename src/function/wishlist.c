#include <stdio.h>
#include <stdbool.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

void wishListShow()
{
  if (current_user.wishlist.Count == 0)
  {
    printf("Wishlist kamu kosong!.\n");
  }
  else
  {
    printf("Berikut adalah isi wishlist-mu:\n");
    char kuantitas[20];
    char total[10];
    for (int index = 0; index < current_user.wishlist.Count; index++)
    {

      printf("%d %s", current_user.wishlist.item[index].posisi, current_user.wishlist.item[index].nama_barang);
    }
    printf("\n");
  }
  execute_command();
}

void wishListClear()
{
  LinkedList newWishList;
  newWishList.Count = 0;
  current_user.wishlist = newWishList;
  printf("Wishlist telah dikosongkan.\n");
  execute_command();
};