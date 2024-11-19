#ifndef USER_H
#define USER_H

#define MAX_LEN 256
#define MAX_USERS 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} User;

extern User users[MAX_USERS];
extern int num_users;
extern int loggedInIndex;

// Fungsi untuk mendaftar pengguna
int registerUser(const char *username, const char *password);

// Fungsi untuk memuat data pengguna dari file
void loadUsersFromFile();

// Fungsi untuk menyimpan data pengguna ke file
void saveUsersToFile();

void logoutUser(); // yah buat logout

#endif
