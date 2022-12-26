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
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll ans = 0, t = 0  ;
    for(int i = 0; i < n; i++) {
        t += a[i].first;
        ans += (a[i].second - t);
    }

    cout << ans << "\n";
}