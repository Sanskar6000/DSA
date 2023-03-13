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

    set<int> s;
    for(int i = 1; i <= 2 * n; i++) {
        s.insert((x + i) % n);
        x += i;
    }
    dbg(s);
    for(auto it : s) {
        if(it == 0) {
            cout << "YES\n";
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