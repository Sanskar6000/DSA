#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> pf(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pf[i] = (pf[i - 1] + a[i]);
    }
    ll ans = 0;

    ll l = 0, r = 1;
    while(l < r && r <= n) {
        ll sum = pf[r] - pf[l];
        if(sum == x) {
            ans++;
            r++;
        }
        else if(sum < x) {
            r++;
        }
        else {
            l++;
        }
    }

    cout << ans;
}