/*      
    phi(n) : number of integers between 1 and n which are co-prime to n

    If p is prime number:
    phi(p) = p - 1
    phi(p^k) = p^k - p^(k - 1)

    if a and b are co-prime:
    phi(ab) = phi(a) * phi(b)

    for not co-prime a and b:
    phi(ab) = phi(a) * phi(b) * (d/phi(d)) with d = gcd(a, b)

    n = p1^a1 * p2^a2 * ...... * pk^ak
    phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ....... * (1 - 1/pk)

    Euler's Theorem:
    a^phi(m) = 1 mod m
    a ^ (m-1) = 1 mod m
*/

#include<bits/stdc++.h>
using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void phi_1_to_n(int n) {
    vector<int> phi_1_to_n(n + 1);
    for (int i = 0; i <= n; i++)
        phi_1_to_n[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi_1_to_n[i] == i) {
            for (int j = i; j <= n; j += i)
                phi_1_to_n[j] -= phi_1_to_n[j] / i;
        }
    }
}


// Euler Totient Function and GCD Sum
ans = Summation(gcd(i, n))

