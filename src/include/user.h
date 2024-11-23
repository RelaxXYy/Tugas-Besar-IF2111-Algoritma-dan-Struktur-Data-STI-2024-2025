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

int user_count(User *users);
int user_index(User *users, char *name);
void add_user(User *users, char *name, char *password, int money);
boolean is_user_valid(User *users, char *name, char *password);
void change_money(User *users, char *name, int money);
boolean is_user_exist(User *users, char *name);


#endif