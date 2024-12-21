#ifndef USER_H
#define USER_H

#include "../History/history.h"
#include "../Cart/cart.h"
#include "../Wishlist/wishlist.h"
#include "../../all_library_headers.h"
#include "../../boolean.h"
#include "../../config.h"



typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Cart cart;
    History riwayat_pembelian;
    Wishlist wishlist;
} User;

typedef struct {
    User buffer[MAX_USER];
    int count;
} ListUser;

extern User current_user;
extern ListUser users;
extern boolean is_user_logged_in;

void create_user(User *current_user);
void create_list_user(ListUser *users);
int user_count(ListUser *users);
int user_index(ListUser *users, char *name);
void add_user(ListUser *users, char *name, char *password, int money);
boolean is_user_valid(ListUser *users, char *name, char *password);
boolean is_user_exist(ListUser *users, char *name);
void add_money(ListUser *users, char *name, int money);
void reduce_money(ListUser *users, char *name, int money);


#endif