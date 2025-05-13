#include "RSA.h"

int gcd(int a, int b)
{
    int max = 1;
    for(int i = 1; i < (a<b)? a:b; i++)
    {
        if(a%i == 0 && b%i == 0)
        {
            max = i;
        }
    }
    return max;
}
int mod_inverse(int e, int phi)
{
    for(int i = 0; i<phi; i++)
    {
        if((e*i)%phi == 1)
        {
            return i;
        }
    }
}
int mod_exp(long long base, long long exp, long mod)
{
    int result = 1;
    while(exp > 0)
    {
        if(exp%2 == 1)
        {
            result = (result*base)%mod;
        }
        base = (base*base)%mod;
        exp = exp/2;
    }
    return result;
}
long long rsa_encrypt(int plaintext, int e, int n)
{
    return mod_exp(plaintext, e, n);
}
long long rsa_decrypt(long long ciphertext, int d, int n)
{
    return mod_exp(ciphertext, d, n);
}