#ifndef WORK_CHALLENGE_H
#define WORK_CHALLENGE_H

#include "../all_library_headers.h"
#include "../boolean.h"
#include "../config.h"

typedef void (*ChallengeFunction)();

typedef struct{
    char name[MAX_LEN];
    ChallengeFunction function;
    int token;
    int cost;
} Challenge;

typedef struct{
    Challenge buffer[MAX_CHALLENGE];

    int count;
} ListChallenge;

extern ListChallenge challenges;

void challenge();
int random_number_generator(int min, int max);
void bioweapon_main();
void rna_translation(const char *dna, char *rna);
void protein_translation(const char *rna, char *protein);

#endif