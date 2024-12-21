#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "random_number_generator.h"

int random_number_generator(int min, int max) {
    unsigned seed = time(NULL);
    seed ^= seed >> 1;    //a
    seed ^= seed >> 12;   //l
    seed ^= seed >> 19;   //s
    seed ^= seed >> 20;   //t
    seed ^= seed >> 18;   //r
    seed ^= seed >> 21;   //u
    seed ^= seed << 11;   //k
    seed ^= seed << 4;    //d
    seed ^= seed << 1;    //a
    seed ^= seed << 20;   //t
    return min + (seed % (max - min + 1));
}