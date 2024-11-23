#include "src/include/boolean.h"
#include "src/include/mesin_kata.h"
#include "src/include/start.h"
#include "src/include/quit.h"
#include <stdio.h>

int main()
{
  start_word();

  while (!isQuit)
  {
    if (is_same_word(current_word,string_to_word("START"))||is_same_word(current_word,string_to_word("START")))
    {
      STARTCOMMAND();
     // printf("%s\n", currentConfig.tab_word);
    }
    else if (is_same_word(current_word,string_to_word("QUIT"))||is_same_word(current_word,string_to_word("QUIT")))
    {
      QUITCOMMAND();
    }
    else if (is_same_word(current_word,string_to_word("STORAGELIST"))||is_same_word(current_word,string_to_word("storagelist")))
    {
      
    }
    else
    {

      printf("Perintah yang anda masukan tidak valid!\n");
    }
    adv_word();
  }

  return 0;
}
