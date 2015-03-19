// Andreas Linz
// alinz@klingt.net
#include <stdio.h>
#include <stdbool.h>

#include "eea.h"

#define PREP_NEXT(NAME)\
NAME = NAME ## A[0] - q * NAME ## A[1];\
NAME ## A[0] = NAME ## A[1];\
NAME ## A[1] = NAME

#define VERBOSE(VERB, CMD)\
if(VERB) { CMD }

#define WIDTH "12"


void eea(long x, long y, result* res, bool verbose) {
    long rA[2] = { x, y };
    long r = x;
    long q = 1L;
    long sA[2] = { 1L , 0L };
    long tA[2] = { 0L , 1L };
    long s = 1L, t = 1L;
    unsigned int i = 0;
    VERBOSE(verbose,
        printf("%3d.) r=%"WIDTH"ld, q=%"WIDTH"ld, s=%"WIDTH"ld, t=%"WIDTH"ld\n", i++, r, q, sA[0], tA[0]);
        printf("%3d.) r=%"WIDTH"ld, q=%"WIDTH"ld, s=%"WIDTH"ld, t=%"WIDTH"ld\n", i++, r, q, sA[1], tA[1]);
    )
    while (r > 0L) {
        q = ( rA[1] > 0L ) ? rA[0] / rA[1] : 0L;
        PREP_NEXT(r);
        if (r != 0L) {
            PREP_NEXT(s);
            PREP_NEXT(t);
        }
        VERBOSE(verbose,
            printf("%3d.) r=%"WIDTH"ld, q=%"WIDTH"ld, s=%"WIDTH"ld, t=%"WIDTH"ld\n", i++, r, q, s, t);
        )
    }
    res->a = sA[1]; res->b = tA[1]; res->gcd = rA[0];
}

#undef PREP_NEXT
#undef VERBOSE
#undef WIDTH
