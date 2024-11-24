#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"

static FILE *pita;
char current_char;
boolean eop;

void start(char *filename) {
    if (filename != NULL) {
        pita = fopen(filename, "r");
        if (pita == NULL) {
            printf("Error opening file '%s'.\n", filename);
            eop = true;
            return;
        }
    } else {
        pita = stdin;
    }
    adv();
}

void adv() {
    int result = fscanf(pita, "%c", &current_char);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    eop = (result == EOF || current_char == MARK);
    if (eop) {
=======
=======
>>>>>>> Stashed changes
    eop = (result == EOF);
    if (eop){
>>>>>>> Stashed changes
        fclose(pita);
    }
}

char get_current_char() {
    return current_char;
}

boolean is_eop() {
    return eop;
}
