/*
 * RSA.c
 *
 *  Created on: May 5, 2025
 *      Author: hp
 */

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
/*********************************************
p = large prime
q = large prime
n = pxq
r = (p-1)(q-1)
e = 3, 5, 17, 65537 (the bigger the more secure
d = (e^-1)mod(r)
Note:
~~~~~~
- r is sometimes called phi or totient
- xmody = the remainder when you divide x by y
- Public Key = (e, n)
- Private Key = (d)

Equations!
~~~~~~~~~~
To encrypt do: (m^e)mod(n) --> where m is the message
To decrypt do: (c^d)mod(n) --> where c is the cipher text
*********************************************/

long long int p = 6011;
long long int q = 7717;
long long int n = p*q;
long long int r = (p-1)*(q-1);
long long int e = 17;
long long int d = (pow(e,-1))%r;

long long int RSA_Encrypt(long long int m)
{
	return (pow(m,e))%n;
}

long long int RSA_Decrypt(long long int c)
{
	return (pow(c,d))%n;
}
