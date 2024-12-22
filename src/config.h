#ifndef CONFIG_H
#define CONFIG_H

#define NMax 256 // Maximum length of a word
#define MAX_LEN 256 // Maximum length of a string
#define INIT_BARANG 10 // Default amount of Barang
#define MAX_USER 100 // Maximum amount of User
#define MAX_LIST 100 // Maximum length of a static list
#define MAX_QUEUE 100 // Maximum length of a queue (static)
#define MAX_CHALLENGE 100 // Maximum length of a list of Challenge
#define MAX_STACK 50 // Maximum length of a stack (static)

extern boolean is_session_started;

extern char *wordlist[];

#endif