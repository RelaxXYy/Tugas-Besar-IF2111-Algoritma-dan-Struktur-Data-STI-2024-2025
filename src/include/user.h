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
int user_index(User *users, const char *name);
void add_user(User *users, const char *name, const char *password, int money);
boolean is_user_valid(User *users, const char *name, const char *password);
void change_money(User *users, const char *name, int money);
boolean is_user_exist(User *users, const char *name);


#endif