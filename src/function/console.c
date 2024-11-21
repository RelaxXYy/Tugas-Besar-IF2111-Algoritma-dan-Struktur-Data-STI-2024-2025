#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"


void print_help() {
    printf("Available commands:\n");
    printf("START - Start the application\n");
    printf("LOAD <filename> - Load a save file\n");
    printf("LOGIN - Login to the system\n");
    printf("LOGOUT - Logout from the system\n");
    printf("REGISTER - Register a new user\n");
    printf("WORK - Work to earn money\n");
    printf("WORK CHALLENGE - Work challenge to earn money\n");
    printf("STORE LIST - List items in the store\n");
    printf("STORE REQUEST - Request a new item for the store\n");
    printf("STORE SUPPLY - Supply requested items to the store\n");
    printf("STORE REMOVE - Remove an item from the store\n");
    printf("SAVE <filename> - Save the current state\n");
    printf("QUIT - Quit the application\n");
}

void starts() {
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void load(const char *filename) {
    printf("Meload /save/%s\n", filename);
    // Add logic to load the file
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void login() {
    char username[MAX_LEN], password[MAX_LEN];
    Word input;

    printf("Username: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), username);

    printf("Password: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), password);

    printf("Anda telah login ke PURRMART sebagai %s.\n", username);
}

void logout() {
    printf("Logout berhasil.\n");
}

void register_user() {
    char username[MAX_LEN], password[MAX_LEN];
    Word input;

    printf("Username: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), username);

    printf("Password: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), password);

    // Add logic to register user
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}

void work() {
    printf("Anda sedang bekerja... harap tunggu.\n");
    // Add logic for work
    printf("Pekerjaan selesai, uang telah ditambahkan ke akun Anda.\n");
}

void work_challenge() {
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL3 (biaya main=500)\n");
    printf("Masukan challenge yang hendak dimainkan: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Tebak Angka challenge selected.\n");
        // Add logic for Tebak Angka challenge
    } else if (choice == 2) {
        printf("W0RDL3 challenge selected.\n");
        // Add logic for W0RDL3 challenge
    } else {
        printf("Invalid choice.\n");
    }
}

void store_list() {
    printf("List barang yang ada di toko:\n");
    // Add logic to list store items
}

void store_request() {
    char item_name[MAX_LEN];
    Word input;

    printf("Nama barang yang diminta: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), item_name);

    // Add logic to request store item
    printf("Barang %s telah diminta.\n", item_name);
}

void store_supply() {
    printf("Apakah kamu ingin menambahkan barang: Terima/Tunda/Tolak\n");
    char response[MAX_LEN];
    Word input;

    start_word();
    input = current_word;
    copy_string(word_to_string(input), response);

    // Add logic to supply store item
    printf("Barang telah ditambahkan ke toko.\n");
}

void store_remove() {
    char item_name[MAX_LEN];
    Word input;

    printf("Nama barang yang akan dihapus: ");
    start_word();
    input = current_word;
    copy_string(word_to_string(input), item_name);

    // Add logic to remove store item
    printf("Barang %s telah berhasil dihapus.\n", item_name);
}

void save(const char *filename) {
    printf("Save file berhasil disimpan.\n");
}

void quit() {
    char response;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
        printf("Data sesi disimpan.\n");
    }
    printf("Kamu keluar dari PURRMART. Dadah ^_^/\n");
    exit(0);
}

void execute_command(char* command) {
    upper_string(command);

    if (is_same_string(command, "HELP") == true) {
        print_help();
    } else if (is_same_string(command, "START") == true) {
        starts();
    } else if (is_same_string(command, "LOAD ") == true) {
        load(command);
    } else if (is_same_string(command, "LOGIN") == true) {
        login();
    } else if (is_same_string(command, "LOGOUT") == true) {
        logout();
    } else if (is_same_string(command, "REGISTER") == true) {
        register_user();
    } else if (is_same_string(command, "WORK") == true) {
        work();
    } else if (is_same_string(command, "WORK CHALLENGE") == true) {
        work_challenge();
    } else if (is_same_string(command, "STORE LIST") == true) {
        store_list();
    } else if (is_same_string(command, "STORE REQUEST") == true) {
        store_request();
    } else if (is_same_string(command, "STORE SUPPLY") == true) {
        store_supply();
    } else if (is_same_string(command, "STORE REMOVE") == true) {
        store_remove();
    } else if (is_same_string(command, "SAVE ") == true) {
        save(command);
    } else if (is_same_string(command, "QUIT") == true) {
        quit();
    } else {
        printf("Unknown command: %s\n", command);
    }
}
int main(){
    char command[MAX_LEN];

    printf("Welcome to PURRMART. Type 'HELP' for a list of commands.\n");
    while (true){
        printf(">>> ");
        get_command();
        printf("%s\n", current_word.tab_word);
        execute_command(current_word.tab_word);
    }
}