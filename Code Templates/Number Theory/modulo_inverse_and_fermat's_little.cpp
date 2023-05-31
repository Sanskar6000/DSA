/*
Fermat's Little Theorem:
if p is prime(gcd(a,p) = 1): !IMP gcd(a, p) = 1
a^(p - 1) = 1 (mod p)

lly,
a ^ (x * (p - 1)) = (a ^ (p - 1)) ^ m = 1 (mod p)
*/

//A^-1 % M = A^M- 2 % M
//inv(A) = A^(m - 2)

/*
inv(A) = (A^(m - 2)) % m
!!holds only when p is prime and gcd(a, m) = 1

Now, ax = 1 (mod m)
where m is not prime
use Euler Totient Function
a^phi(m) = 1 (mod m)
!!x = a^(phi(m) - 1) when gcd(a, m) = 1

*/ 

//!!General Formula : inv(x) = (a^(phi(m) - 1)) % m  where gcd(a,m) = 1

/*
When m is prime, 
inv(a) = (a^(m - 2)) % m; ---> log(M)
When m is not prime, 
inv(a) = (a^(phi(m) - 2)) % m; ----> sqrt(m) + log(m)
*/
int inverse(int a, int m) {
    return binary_expo(a, m - 2, m);
}