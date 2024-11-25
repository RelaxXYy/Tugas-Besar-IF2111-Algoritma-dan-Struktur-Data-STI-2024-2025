#include <stdio.h>
#include "../include/user.h"
#include "../include/mesin_kata.h"
#include "../include/config.h"

void handle_logout(char *current_user) {
    printf(">> LOGOUT\n");
    
    // Check if a user is currently logged in
    if (current_user[0] != '\0') {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", current_user);

        // Reset the current user
        current_user[0] = '\0';
}
