#include "mesin_karakter.h"

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
    eop = (result == EOF || current_char == MARK);
    if (eop){
        fclose(pita);
    }
}

char get_current_char() {
    return current_char;
}

boolean is_eop() {
    return eop;
}

void adv_line() {
    int result = fscanf(pita, "%c", &current_char);
    eop = (result == EOF);
    if (eop){
        fclose(pita);
    }
}
