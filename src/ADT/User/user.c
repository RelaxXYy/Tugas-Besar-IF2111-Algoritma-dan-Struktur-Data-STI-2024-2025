#include "user.h"

void create_user(User *current_user) {
    copy_string("", (*current_user).name);
    copy_string("", (*current_user).password);
    (*current_user).money = 0;
}

void create_list_user(ListUser *users) {
    (*users).count = 0;
}

int user_count(ListUser *users) {
    return (*users).count;
}

int user_index(ListUser *users, char *name) {
    for(int i = 0; i<user_count(users); i++){
        if(is_same_string((*users).buffer[i].name, name)) return i;
    }
    return -1;
}

void add_user(ListUser *users, char *name, char *password, int money){
    int i = user_count(users);  
    copy_string(name, (*users).buffer[i].name);
    copy_string(password, (*users).buffer[i].password);
    (*users).buffer[i].money = money;
    (*users).count ++;
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
