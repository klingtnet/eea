// Andreas Linz
// alinz@klingt.net
#ifndef EEA_H_INCLUDED
#define EEA_H_INCLUDED

typedef struct {
    long a;
    long b;
    long gcd;
} result;

void eea(long, long, result*, bool);

#endif // EEA_H_INCLUDED
