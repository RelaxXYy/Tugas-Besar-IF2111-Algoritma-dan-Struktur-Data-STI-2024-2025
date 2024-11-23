#include "../include/mesin_karakter.h"
#include <stdio.h>
#include "../include/boolean.h"

boolean isQuit;

void QUITCOMMAND()
{
  printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
  adv();
  if (current_char == 'Y' || current_char == 'y')
  {
    // Masukan function simpan sesi disini
  }
  else
  {
    printf("Kamu keluar dari PURRMART\n");
    printf("Dadah ^_^/");
  }
  isQuit = true;
}