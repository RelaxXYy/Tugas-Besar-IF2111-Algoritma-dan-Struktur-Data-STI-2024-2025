#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

User users[MAX_USER];

int user_count(User *users) {
    int i = 0;
    while (users[i].name[0] != '\0') {
        i++;
    }
    return i;
}

int user_index(User *users, const char *name) {
    int i = 0;
    while (users[i].name[0] != '\0') {
        if (is_same_string(users, name) == true) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_user(User *users, const char *name, const char *password, int money){
    int i = user_count(users);
    copy_string(users[i].name, name);
    copy_string(users[i].password, password);
    users[i].money = money;
}

boolean is_user_exist(User *users, const char *name){
    return user_index(users, name) != -1;
}

boolean is_user_valid(User *users, const char *name, const char *password){
    int i = user_index(users, name);
    if (i == -1) {
        return false;
    }
    return is_same_string(users[i].password, password);
}

void change_money(User *users, const char *name, int money){
    int i = user_index(users, name);
    users[i].money += money;
}
