// Monotonic Function
// Time required by machines: 0 0 0 0 0 1 1 1 1 1
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;
 
bool isGood(ll mid, vector<ll> &k, ll t, ll n) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += mid/k[i];
        if(ans >= t) break;
    }
    return (ans >= t);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, t;
    cin >> n >> t;
 
    vector<ll> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];
 
    ll l = 1, r = 1e18, ans = 0;
    while(l <= r) {
        ll mid = r - (r - l)/2;
        // cout << mid << "\n";
        if(isGood(mid, k, t, n)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
        // cout << l << " " << r << "\n";
    }
 
    cout << ans << "\n";
}