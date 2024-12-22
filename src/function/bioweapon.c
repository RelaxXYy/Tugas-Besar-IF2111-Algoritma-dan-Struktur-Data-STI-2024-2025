#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "bioweapon.h"

typedef struct {
    char name[100];
    char DNA[100];
    char kodeInput[100];
} bioweapon;

void rna_translation(const char *dna, char *rna) {
    int i = 0;
    while (dna[i] != '\0') {
        if (dna[i] == 'A') {
            rna[i] = 'U';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else if (dna[i] == 'G') {
            rna[i] = 'C';
        } else {
            rna[i] = '\0';
        }
        i++;
    }
    rna[i] = '\0';
}

void protein_translation(const char *rna, char proteins[3][300], int *protein_lengths) {
    int rna_length = 0;
    while (rna[rna_length] != '\0') {
        rna_length++;
    }

    for (int offset = 0; offset < 3; offset++) {
        protein_lengths[offset] = 0;
    }

    for (int offset = 0; offset < 3; offset++) {
        int protein_index = 0;

        for (int i = offset; i + 2 < rna_length; i += 3) {
            char codon[4] = {rna[i], rna[i + 1], rna[i + 2], '\0'};

            if (is_same_string(codon, "UUU") || is_same_string(codon, "UUC")) {
                proteins[offset][protein_index++] = 'F';
            } else if (is_same_string(codon, "UUA") || is_same_string(codon, "UUG") ||
                       is_same_string(codon, "CUU") || is_same_string(codon, "CUC") ||
                       is_same_string(codon, "CUA") || is_same_string(codon, "CUG")) {
                proteins[offset][protein_index++] = 'L';
            } else if (is_same_string(codon, "AUU") || is_same_string(codon, "AUC") || is_same_string(codon, "AUA")) {
                proteins[offset][protein_index++] = 'I';
            } else if (is_same_string(codon, "AUG")) {
                proteins[offset][protein_index++] = 'M';
            } else if (is_same_string(codon, "GUU") || is_same_string(codon, "GUC") ||
                       is_same_string(codon, "GUA") || is_same_string(codon, "GUG")) {
                proteins[offset][protein_index++] = 'V';
            } else if (is_same_string(codon, "UCU") || is_same_string(codon, "UCC") ||
                       is_same_string(codon, "UCA") || is_same_string(codon, "UCG") ||
                       is_same_string(codon, "AGU") || is_same_string(codon, "AGC")) {
                proteins[offset][protein_index++] = 'S';
            } else if (is_same_string(codon, "CCU") || is_same_string(codon, "CCC") ||
                       is_same_string(codon, "CCA") || is_same_string(codon, "CCG")) {
                proteins[offset][protein_index++] = 'P';
            } else if (is_same_string(codon, "ACU") || is_same_string(codon, "ACC") ||
                       is_same_string(codon, "ACA") || is_same_string(codon, "ACG")) {
                proteins[offset][protein_index++] = 'T';
            } else if (is_same_string(codon, "GCU") || is_same_string(codon, "GCC") ||
                       is_same_string(codon, "GCA") || is_same_string(codon, "GCG")) {
                proteins[offset][protein_index++] = 'A';
            } else if (is_same_string(codon, "UAU") || is_same_string(codon, "UAC")) {
                proteins[offset][protein_index++] = 'Y';
            } else if (is_same_string(codon, "CAU") || is_same_string(codon, "CAC")) {
                proteins[offset][protein_index++] = 'H';
            } else if (is_same_string(codon, "CAA") || is_same_string(codon, "CAG")) {
                proteins[offset][protein_index++] = 'Q';
            } else if (is_same_string(codon, "AAU") || is_same_string(codon, "AAC")) {
                proteins[offset][protein_index++] = 'N';
            } else if (is_same_string(codon, "AAA") || is_same_string(codon, "AAG")) {
                proteins[offset][protein_index++] = 'K';
            } else if (is_same_string(codon, "GAU") || is_same_string(codon, "GAC")) {
                proteins[offset][protein_index++] = 'D';
            } else if (is_same_string(codon, "GAA") || is_same_string(codon, "GAG")) {
                proteins[offset][protein_index++] = 'E';
            } else if (is_same_string(codon, "UGU") || is_same_string(codon, "UGC")) {
                proteins[offset][protein_index++] = 'C';
            } else if (is_same_string(codon, "UGG")) {
                proteins[offset][protein_index++] = 'W';
            } else if (is_same_string(codon, "GGU") || is_same_string(codon, "GGC") ||
                       is_same_string(codon, "GGA") || is_same_string(codon, "GGG")) {
                proteins[offset][protein_index++] = 'G';
            } else {
                proteins[offset][protein_index++] = 'X'; // Jika codon tidak ditemukan, diasumsikan sebagai 'X'
            }
        }
        proteins[offset][protein_index] = '\0';
        protein_lengths[offset] = protein_index;
    }
}

void bioweapon_main() {
    bioweapon weapon;

    printf("Masukan nama senjata biologis: ");
    get_line();
    copy_string(word_to_string(current_word), weapon.name);

    printf("Masukan sekuens DNA: ");
    get_line();
    copy_string(word_to_string(current_word), weapon.DNA);

    printf("Masukan kode rahasia: ");
    get_line();
    copy_string(word_to_string(current_word), weapon.kodeInput);

    char rnaSequence[100];
    char proteins[3][300];
    int protein_lengths[3];

    rna_translation(weapon.DNA, rnaSequence);
    protein_translation(rnaSequence, proteins, protein_lengths);

    for (int offset = 0; offset < 3; offset++) {
        printf("Protein (frame %d): %s\n", offset, proteins[offset]);
    }

    int found = 0;
    for (int offset = 0; offset < 3; offset++) {
        for (int i = 0; i < protein_lengths[offset]; i++) {
            int j = 0;
            while (weapon.kodeInput[j] != '\0' && proteins[offset][i + j] == weapon.kodeInput[j]) {
                j++;
            }
            if (weapon.kodeInput[j] == '\0') {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam sistem!\n");
        enqueue_barang(&qbarangs, weapon.name);
    } else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }
}