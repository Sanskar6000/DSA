#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b % 2) {
            ans = (ans * a) % mod;
            b--;
        }
        else {
            a = (a * a) % mod;
            b = b/2;
        }
    }
    return ans;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << power(power(a, b), c) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}