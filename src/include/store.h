#ifndef STORE_H
#define STORE_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

void store_request(char *name);
void store_request_main();
void store_supply(char *name, int price);
void store_supply_main();
void store_list_main();
void store_remove(char *name);
void store_remove_main();

#endif