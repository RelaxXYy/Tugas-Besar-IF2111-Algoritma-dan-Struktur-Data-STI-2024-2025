#include <stdio.h>
#include <stdbool.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

int isInteger(char *str)
{
  if (str == NULL || *str == '\0')
  {
    return 0;
  }

  // Handle optional leading sign
  if (*str == '+' || *str == '-')
  {
    str++;
  }

  // Check if the remaining characters are all digits
  while (*str != '\0' && *str != '\n')
  {
    if (*str < '0' || *str > '9')
    {
      return 0;
    }
    str++;
  }

  return 1;
}

// Function to convert a string to an integer
int strToInt(char *str)
{
  int result = 0;
  int sign = 1;

  // Handle optional leading sign
  if (*str == '-')
  {
    sign = -1;
    str++;
  }
  else if (*str == '+')
  {
    str++;
  }

  // Convert each digit character to an integer and build the result
  while (*str != '\0' && *str != '\n')
  {
    result = result * 10 + (*str - '0');
    str++;
  }

  return result * sign;
}
void history(char *jumlah)
{
  if (isInteger(jumlah))
  {
    int limit = strToInt(jumlah);
    if (limit == 0)
    {
      printf("Masukan jumlah riwayat yang ingin ditampilkan.\n");
    }
    else if (current_user.riwayat_pembelian.IndexTop == 0)
    {
      printf("Kamu belum membeli barang apapun!.\n");
    }
    else
    {
      printf("Riwayat pembelian barang:\n");
      char kuantitas[20];
      char total[10];
      int loop = current_user.riwayat_pembelian.IndexTop > limit ? limit : current_user.riwayat_pembelian.IndexTop;
      for (int index = 0; index < loop; index++)
      {

        printf("%d %s", (index + 1), current_user.riwayat_pembelian.Elements[index].Key);
      }
    }
  }
  else
  {
    printf("Masukan jumlah riwayat berupa angka.\n");
  }

  execute_command();
}