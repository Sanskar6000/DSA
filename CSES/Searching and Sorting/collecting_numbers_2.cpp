//Ans -> number of inversions
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }

    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(b[i] > b[i + 1]) ans++;
    }
    int l, r;
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;

        if(a[l] + 1 <= n)
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}