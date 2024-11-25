#include <stdio.h>
#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

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
            rna[i] = '\0'; // Handle invalid characters
        }
        i++;
    }
    rna[i] = '\0'; // Null-terminate the RNA string
}

void protein_translation(const char *rna, char *protein) {
    int rna_length = 0;
    while (rna[rna_length] != '\0') {
        rna_length++;
    }
    
    int protein_index = 0;

    for (int offset = 0; offset <= rna_length - 3; offset++) {
        for (int i = offset; i <= rna_length - 3; i += 3) {
            char codon[4] = {rna[i], rna[i + 1], rna[i + 2], '\0'};

            // Daftar inisial protein
            if (is_same_string(codon, "UUU") || is_same_string(codon, "UUC")) {
                protein[protein_index++] = 'F'; // Fenilalanin (Phe)
            } else if (is_same_string(codon, "UUA") || is_same_string(codon, "UUG") ||
                       is_same_string(codon, "CUU") || is_same_string(codon, "CUC") ||
                       is_same_string(codon, "CUA") || is_same_string(codon, "CUG")) {
                protein[protein_index++] = 'L'; // Leusin (Leu)
            } else if (is_same_string(codon, "AUU") || is_same_string(codon, "AUC") || is_same_string(codon, "AUA")) {
                protein[protein_index++] = 'I'; // Isoleusin (Ile)
            } else if (is_same_string(codon, "AUG")) {
                protein[protein_index++] = 'M'; // Metionin (Met)
            } else if (is_same_string(codon, "GUU") || is_same_string(codon, "GUC") ||
                       is_same_string(codon, "GUA") || is_same_string(codon, "GUG")) {
                protein[protein_index++] = 'V'; // Valin (Val)
            } else if (is_same_string(codon, "UCU") || is_same_string(codon, "UCC") ||
                       is_same_string(codon, "UCA") || is_same_string(codon, "UCG") ||
                       is_same_string(codon, "AGU") || is_same_string(codon, "AGC")) {
                protein[protein_index++] = 'S'; // Serin (Ser)
            } else if (is_same_string(codon, "CCU") || is_same_string(codon, "CCC") ||
                       is_same_string(codon, "CCA") || is_same_string(codon, "CCG")) {
                protein[protein_index++] = 'P'; // Prolin (Pro)
            } else if (is_same_string(codon, "ACU") || is_same_string(codon, "ACC") ||
                       is_same_string(codon, "ACA") || is_same_string(codon, "ACG")) {
                protein[protein_index++] = 'T'; // Treonin (Thr)
            } else if (is_same_string(codon, "GCU") || is_same_string(codon, "GCC") ||
                       is_same_string(codon, "GCA") || is_same_string(codon, "GCG")) {
                protein[protein_index++] = 'A'; // Alanin (Ala)
            } else if (is_same_string(codon, "UAU") || is_same_string(codon, "UAC")) {
                protein[protein_index++] = 'Y'; // Tirosin (Tyr)
            } else if (is_same_string(codon, "CAU") || is_same_string(codon, "CAC")) {
                protein[protein_index++] = 'H'; // Histidin (His)
            } else if (is_same_string(codon, "CAA") || is_same_string(codon, "CAG")) {
                protein[protein_index++] = 'Q'; // Glutamin (Gln)
            } else if (is_same_string(codon, "AAU") || is_same_string(codon, "AAC")) {
                protein[protein_index++] = 'N'; // Asparagin (Asn)
            } else if (is_same_string(codon, "AAA") || is_same_string(codon, "AAG")) {
                protein[protein_index++] = 'K'; // Lisin (Lys)
            } else if (is_same_string(codon, "GAU") || is_same_string(codon, "GAC")) {
                protein[protein_index++] = 'D'; // Asam aspartat (Asp)
            } else if (is_same_string(codon, "GAA") || is_same_string(codon, "GAG")) {
                protein[protein_index++] = 'E'; // Asam glutamat (Glu)
            } else if (is_same_string(codon, "UGU") || is_same_string(codon, "UGC")) {
                protein[protein_index++] = 'C'; // Sistein (Cys)
            } else if (is_same_string(codon, "UGG")) {
                protein[protein_index++] = 'W'; // Triptofan (Trp)
            } else if (is_same_string(codon, "CGU") || is_same_string(codon, "CGC") ||
                       is_same_string(codon, "CGA") || is_same_string(codon, "CGG") ||
                       is_same_string(codon, "AGA") || is_same_string(codon, "AGG")) {
                protein[protein_index++] = 'R'; // Arginin (Arg)
            } else if (is_same_string(codon, "GGU") || is_same_string(codon, "GGC") ||
                       is_same_string(codon, "GGA") || is_same_string(codon, "GGG")) {
                protein[protein_index++] = 'G'; // Glisin (Gly)
            } else {
                protein[protein_index++] = 'X'; // Jika codon tidak diketahui asam aminonya maka diasumsikan bahwa inisalnya X
            }
        }
    }
    protein[protein_index] = '\0';
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
    char proteinSequence[300];

    rna_translation(weapon.DNA, rnaSequence);
    protein_translation(rnaSequence, proteinSequence);

    int found = 0;

    for (int i = 0; proteinSequence[i] != '\0'; i++) {
        int j = 0;
        while (weapon.kodeInput[j] != '\0' && proteinSequence[i+j] == weapon.kodeInput[j]) {
            j++;
        }
        if (weapon.kodeInput[j] == '\0') {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam sistem!\n");
        enqueue_barang(&qbarangs, weapon.name);
    } else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }
}