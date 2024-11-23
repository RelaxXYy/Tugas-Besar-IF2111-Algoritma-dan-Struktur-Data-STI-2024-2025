#include "../include/start.h"
#include <stdio.h>

Word currentConfig;

void STARTCOMMAND()
{
  readConfig();
};

void readConfig()
{
  FILE *file;

  char ch;

  file = fopen("/Users/irdinailmuna/Downloads/Tugas-Besar-IF2111-Algoritma-dan-Struktur-Data-STI-2024-2025/data/config.txt", "r");

  if (NULL != file)
  {
    // Printing what is written in file
    // character by character using loop.
    currentConfig.length=0;
    while ((ch = fgetc(file)) != EOF)
    {
      if (currentConfig.length < NMax)
      { // jika lebih akan terpotong
        currentConfig.tab_word[currentConfig.length++] = ch;
      }
      else
        break;
    }
    currentConfig.tab_word[currentConfig.length] = '\0';
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

  }
  else
  {
    printf("File not found\n");
  }
  fclose(file);
}