#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include "all_library_headers.h"
#include "boolean.h"

#define MARK '.'
#define BLANK ' '

extern char current_char;
extern boolean eop;

void start();
void adv();
char get_current_char();
boolean is_eop();
void adv_line();

#endif
