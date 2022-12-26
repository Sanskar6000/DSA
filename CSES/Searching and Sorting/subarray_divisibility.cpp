#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> r(n, 0);
    ll pf = 0, ans = 0;
    r[0] = 1;
    for(int i = 0; i < n; i++) {
        pf += a[i];

        r[(pf % n + n) % n]++;
    }
    for(ll i : r) ans += (i*(i - 1))/2;
    
    cout << ans;
}