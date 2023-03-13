#include<bits/stdc++.h>
using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    map<int, int> mp;
    set<ll> st;
    for(auto &i : a) {
        cin >> i;
        st.insert(i);
        mp[i] = m + 1;
    } 
    
    ll ans = n * ((m * (m + 1))/2);
    // ll ans = 0;

    set<ll> s;
    set<ll> sz;
    for(int i = 1; i <= m; i++) {
        ll l, r;
        cin >> l >> r;
        ll sz = s.size();

        s.insert(l);
       
        // if(mp.find(r) == mp.end()) ans += ((i * (i + 1))/2);
        // else ans += ((i * (i + 1))/2) - mp[r];
        if(s.size() > sz) {
            if(mp.find(r) == mp.end()) ans += ((i * (i + 1))/2) - mp[r];
            else ans += ((i * (i + 1))/2) - mp[r];
        }
        else {
            if(mp.find(r) == mp.end()) ans += ((i * (i - 1))/2) - mp[r] - n; 
            ans += ((i * (i - 1))/2) + 1 - mp[r] - n;
        }
        if(mp.find(r) == mp.end()) mp[r] = m - i;
        else mp[r] += (m - i);
        mp[a[l - 1]] -= (m - i);
        a[l - 1] = r;
        // dbg(mp);
        if(mp[a[l - 1]] <= 0) mp.erase(mp.find(a[l - 1]));
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}