// Print all primes in range (L, R) (L, R) -> 10^12 difference(L, R) = 1e6
// Generate primes till sqrt(r)
// create (r - l + 1) size dummy array
// mark primes in dummy array
#include<bits/stdc++.h>
using namespace std;

int N = 1e6;
bool sieve[N + 1];
void createSieve() {
    memset(sieve, false, sizeof(sieve));

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(sieve[i]) {
            for(int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N) {
    vector<int> ans;
    for(int i = 2; i <= N; i++) {
        if(sieve[i]) ans.push_back(i);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;

        int limit = sqrt(r) + 1;

        vector<int> primes = generatePrimes(limit);

        vector<int> a(r - l + 1, 1);
        for(auto pr : primes) {
            int firstMultiple = (l/pr) * pr;
            if(firstMultiple < l) firstMultiple += pr;

            for(int j = max(firstMultiple, pr * pr); j <= r; j += pr) {
                a[j - l] = 0;
            }
        }

        for(int i = l; i <= r; i++) {
            if(a[i - l] == 1) cout << i << ' ';
        }
    }
}