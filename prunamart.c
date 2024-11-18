#include <stdio.h>
#include <stdlib.h>
int cmpStr(char *a, char *b)
{
  int flag = 0;
  while (*a != '\0' && *b != '\0') // while loop
  {
    if (*a != *b)
    {
      flag = 1;
    }
    a++;
    b++;
  }
  if (*a != '\0' || *b != '\0')
    return 1;
  if (flag == 0)
    return 0;
  else
    return 1;
}

void appendChar(char *str, char ch)
{
  int len = 0;
  // Find the length of the string
  while (str[len] != '\0')
  {
    len = len + 1;
  }

  // Place the character at the end
  str[len] = ch;

  // Null-terminate the string
  str[len + 1] = '\0';
}

void readConfig(char *str)
{
  FILE *file_ptr;

  char ch;

  file_ptr = fopen("config.txt", "r");

  if (NULL != file_ptr)
  {
    // Printing what is written in file
    // character by character using loop.
    while ((ch = fgetc(file_ptr)) != EOF)
    {
      appendChar(str, ch);
    }
    // Closing the file
  }
  fclose(file_ptr);
}

int main()
{
  char command[20] = "";
  char config[200] = "";
  while (cmpStr(command, "QUIT") != 0)
  {
    printf("Enter command : ");
    scanf("%s", command);
    if (cmpStr(command, "START") == 0)
    {
      readConfig(config);
      printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
    }
  }

  return 0;
}
