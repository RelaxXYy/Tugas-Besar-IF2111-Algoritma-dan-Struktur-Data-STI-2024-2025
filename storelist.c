#include <stdio.h>
#include "../include/storelist.h"
#include "../include/barang.h"
#include "../include/start.h"
#include "../include/mesin_kata.h"

TabBarang tabBarang;

void STORELISTCOMMAND()
{
  int i = 0;
  int line = 1;
  Word tempWord;
  tabBarang.count = tempWord.length = 0;
  boolean isName = false;
  boolean isLoop = currentConfig.tab_word[i] != '\0';
  while (isLoop)
  {
    if (currentConfig.tab_word[i] == '\n')
    {
      if (tabBarang.count == 0)
      {
        for (int j = 0; j < tempWord.length; j++)
        {
          tabBarang.count = (tabBarang.count * 10) + (tempWord.tab_word[j] - '0');
        }
      }
      else
      {
        copy_string(tempWord.tab_word, tabBarang.item[line - 1].name);
        line++;
        if (line == (tabBarang.count + 1))
        {
          isLoop = false;
        }
      }
      tempWord.length = 0;
      tempWord.tab_word[0] = '\0';
      isName = false;
    }
    else
    {
      if (currentConfig.tab_word[i] == ' ' && !isName)
      {
        tempWord.length = 0;
        tempWord.tab_word[0] = '\0';
        isName = true;
      }
      else
      {
        tempWord.tab_word[tempWord.length++] = currentConfig.tab_word[i];
        tempWord.tab_word[tempWord.length] = '\0';
      }
    }
    i++;
  }

  boolean isPrint;
  if (tabBarang.count == 0)
  {
    printf("TOKO KOSONG\n");
  }
  else
  {
    printf("List barang yang ada di toko : \n");
    for (int i = 0; i < tabBarang.count; i++)
    {
      {
        isPrint = true;
        for (int j = 0; j < tabBarang.count; j++)
        {
          if (tabBarang.item[i].name == tabBarang.item[j].name && i != j)
          {
            isPrint = false;
          }
        }
        if (isPrint)
        {
          printf("- %s\n", tabBarang.item[i].name);
        }
      }
    }
  }
}