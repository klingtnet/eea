// Andreas Linz
// alinz@klingt.net
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "eea.h"
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void usage() {
    printf("./eaa X Y [-v]\n\t\
where X,Y are both integers\n\t\
-v  be more verbose\n");
}

void readLong(char* s, long* x) {
    int err;
    err = sscanf(s, "%ld", x);
    if ( err == 0 || err == EOF ) {
        fprintf(stderr, "\"%s\" is not an integer!\n", s);
        usage();
        exit(1);
    }
}

int main(int argc, char** argv) {
    bool verbose = false;
    if (argc < 3) {
        usage();
        return 1;
    } else if ( argc == 4 && strncmp(argv[3], "-v", 2) == 0) {
        verbose = true;
    }
    long x, y;
    readLong(argv[1], &x);
    readLong(argv[2], &y);
    if (x < y) {
        // XOR swap
        x ^= y; y ^= x; x ^= y;
    }
    result res;
    eea(x, y, &res, verbose);
    assert(res.a*x + res.b*y == res.gcd);
    printf("Result:\n\
    %ld * %ld + %ld * %ld\n\
    = gcd(%ld, %ld)\n\
    = %ld\n", res.a, x, res.b, y, x, y, res.gcd);
}

