#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

void solve() {
    int n, x, p;
    cin >> n >> x >> p;

    for(int i = 1; i <= min(2*n, p); i++) {
        if((x + (i * (i + 1)/2)) % n == 0) {
            cout <<"YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}