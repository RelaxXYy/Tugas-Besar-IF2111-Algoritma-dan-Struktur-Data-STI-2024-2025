#ifndef USER_H
#define USER_H

#include "all_library_headers.h"
#include "boolean.h"
#include "config.h"

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User buffer[MAX_USER];
    int count;
} ListUser;

int user_count(ListUser *users);
int user_index(ListUser *users, char *name);
void add_user(ListUser *users, char *name, char *password, int money);
boolean is_user_valid(ListUser *users, char *name, char *password);
boolean is_user_exist(ListUser *users, char *name);
void add_money(ListUser *users, char *name, int money);
void subtract_money(ListUser *users, char *name, int money);


#endif