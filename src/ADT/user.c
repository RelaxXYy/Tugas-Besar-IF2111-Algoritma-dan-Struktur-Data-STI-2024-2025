#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

void create_user(User *current_user) {
    copy_string("", (*current_user).name);
    copy_string("", (*current_user).password);
    (*current_user).money = 0;
}

void create_list_user(ListUser *users) {
    (*users).count = 0;
}

int user_count(ListUser *users) {
    int i = 0;
    while ((*users).buffer[i].name[0] != '\0') {
        i++;
    }
    return i;
}

int user_index(ListUser *users, char *name) {
    int i = 0;
    while ((*users).buffer[i].name[0] != '\0') {
        if (is_same_string((*users).buffer[i].name, name) == true) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_user(ListUser *users, char *name, char *password, int money){
    int i = user_count(users);  
    copy_string(name, (*users).buffer[i].name);
    copy_string(password, (*users).buffer[i].password);
    (*users).buffer[i].money = money;
}

boolean is_user_exist(ListUser *users, char *name){
    return user_index(users, name) != -1;
}

boolean is_user_valid(ListUser *users, char *name, char *password){
    int i = user_index(users, name);
    if (i == -1) {
        return false;
    }
    return is_same_string((*users).buffer[i].password, password);
}

void add_money(ListUser *users, char *name, int money){
    int i = user_index(users, name);
    (*users).buffer[i].money += money;
}

void reduce_money(ListUser *users, char *name, int money){
    int i = user_index(users, name);
    (*users).buffer[i].money -= money;
}
