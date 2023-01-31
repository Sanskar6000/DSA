/*
Fermat's Little Theorem:
if p is prime(gcd(a,p) = 1): !IMP gcd(a, p) = 1
a^(p - 1) = 1 (mod p)

lly,
a ^ (x * (p - 1)) = (a ^ (p - 1)) ^ m = 1 (mod p)
*/

//A^-1 % M = A^M- 2 % M
//inv(A) = A^(m - 2)
int inverse(int a, int m) {
    return binary_expo(a, m - 2, m);
}