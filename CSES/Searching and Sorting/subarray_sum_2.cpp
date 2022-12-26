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

    vector<ll> a(n);
    map<ll, ll> m;
    //Considering same subarray
    m[0] = 1;
    ll pf = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pf += a[i];
        ans += m[pf - x];
        m[pf]++;
    } 
    
    cout << ans << "\n";
    
}