#ifndef RSA_H
#define RSA_H

#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b);
int mod_inverse(int e, int phi);
int mod_exp(long long base, long long exp, long mod);
long long rsa_encrypt(int plaintext, int e, int n);
long long rsa_decrypt(long long ciphertext, int d, int n);
#endif