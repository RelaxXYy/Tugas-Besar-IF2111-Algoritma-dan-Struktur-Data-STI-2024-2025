#include <stdio.h>
#include <stdbool.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"

int getHargaByNama(char *name)
{
  int i = 0;
  while (barangs.buffer[i].name[0] != '\0')
  {
    char str1[MAX_LEN], str2[MAX_LEN];
    make_upper_string(barangs.buffer[i].name, str1);
    make_upper_string(name, str2);
    if (is_same_string(str1, str2) == true)
    {
      return barangs.buffer[i].price;
    }
    i++;
  }

  return 0;
}

char intToStr(int num, char str[])
{
  int i = 0;

  // Handle negative numbers
  if (num < 0)
  {
    str[i++] = '-';
    num = -num; // Make the number positive
  }

  // Extract digits and store in reverse order
  do
  {
    str[i++] = (num % 10) + '0'; // Get last digit and convert to char
    num /= 10;
  } while (num > 0);

  // Reverse the string
  str[i] = '\0'; // Null-terminate the string
  for (int j = (str[0] == '-' ? 1 : 0), k = i - 1; j < k; j++, k--)
  {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
  return str;
}

void cartShow()
{
  if (current_user.keranjang.Count == 0)
  {
    printf("Keranjang kamu kosong!.\n");
  }
  else
  {
    printf("Berikut adalah isi keranjangmu.\n");
    printf("%-10s %-20s %-10s\n", "Kuantitas", "Nama", "Total");
    char kuantitas[20];
    char total[10];
    int biaya = 0;
    for (int index = 0; index < current_user.keranjang.Count; index++)
    {
      biaya = biaya + getHargaByNama(current_user.keranjang.Elements[index].Key) * current_user.keranjang.Elements[index].Value;
      printf("%-10s %-20s %-10s\n", intToStr(current_user.keranjang.Elements[index].Value, kuantitas), current_user.keranjang.Elements[index].Key, intToStr(biaya, total));
    }
    printf("Total biaya yang harus dikeluarkan adalah %d \n", biaya);
  }
  execute_command();
}