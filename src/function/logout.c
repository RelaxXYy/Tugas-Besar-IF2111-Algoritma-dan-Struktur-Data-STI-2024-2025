#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"


void handle_logout() {
    if(is_user_logged_in){
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", current_user.name);
        is_user_logged_in = false;
        create_user(&current_user);
    }
    else{
        printf("Tidak ada user yang sedang login.\n");
    }
    execute_command();
    
}