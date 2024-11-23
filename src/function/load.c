#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

User users[MAX_USER];
ListBarang barangs[INIT_BARANG];

void load(User* users, Barang* barangs) {
    start(NULL);
    get_line();
    printf("../../save/%s", current_word);
    start("../../save/%s", current_word);
}