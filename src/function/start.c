#include "../include/all_ADT_headers.h"
#include <stdio.h>

void start_command()
{
    load(NULL);
    is_session_started = true;
    printf("%s\n", "Konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
    printf("%s\n", "Konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
    printf("****************************************\n");
    printf("*    Silahkan Bergabung di PURRMART    *\n");
    printf("****************************************\n");
    printf("*   1. LOGIN                           *\n");
    printf("*   2. REGISTER                        *\n");
    printf("*   3. LOGOUT                          *\n");
    printf("****************************************\n");
    printf("*   Pilih Command atau ketik 'HELP'!   *\n");
    printf("****************************************\n");
    execute_command();
}
