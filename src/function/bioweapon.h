#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include "../all_library_headers.h"
#include "../boolean.h"
#include "../config.h"

void rna_translation(const char *dna, char *rna);
void protein_translation(const char *rna, char proteins[3][300], int *protein_lengths);
void bioweapon_main();

#endif