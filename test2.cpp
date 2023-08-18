#include <iostream>

using namespace std;

const int MOD = 1000000007;

// Function to calculate (x^y) % MOD
long long mod_pow(long long x, long long y, int mod) {
    long long result = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return result;
}

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

int allocateProcesses(int n_intervals, int n_processes) {
    // Calculate n!
    long long n_fact = factorial(n_intervals);

    // Calculate (n - m)!
    long long n_minus_m_fact = factorial(n_intervals - n_processes);

    // Calculate the number of permutations (n! / (n - m)!) % MOD
    long long num_permutations = (n_fact * mod_pow(n_minus_m_fact, MOD - 2, MOD)) % MOD;

    return static_cast<int>(num_permutations);
}

int main() {
    int n_intervals = 2;
    int n_processes = 3;

    int output = allocateProcesses(n_intervals, n_processes);
    cout << output << endl;  // Output: 6

    return 0;
}
