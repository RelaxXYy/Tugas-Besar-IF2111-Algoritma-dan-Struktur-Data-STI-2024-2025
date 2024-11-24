#include "src/include/boolean.h"
#include "src/include/mesin_kata.h"
#include "src/include/start.h"
#include "src/include/storelist.h"
#include "src/include/quit.h"
#include <stdio.h>

int main()
{
  start_word();

  while (!isQuit)
  {
    if (is_same_word(current_word, string_to_word("START")) || is_same_word(current_word, string_to_word("start")))
    {
      STARTCOMMAND();
      // printf("%s\n", currentConfig.tab_word);
    }
    else if (is_same_word(current_word, string_to_word("QUIT")) || is_same_word(current_word, string_to_word("quit")))
    {
      QUITCOMMAND();
    }
    else if (currentConfig.length > 0 && (is_same_word(current_word, string_to_word("STORE LIST")) || is_same_word(current_word, string_to_word("store list"))))
    {
      STORELISTCOMMAND();
    }
    else
    {
      // printf("%s\n", current_word.tab_word);
      printf("Perintah yang anda masukan tidak valid!\n");
    }
    adv_word();
  }

  return 0;
}
