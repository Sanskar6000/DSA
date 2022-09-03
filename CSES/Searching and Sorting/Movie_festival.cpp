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
    vector<pair<int,int>> a(n);

    for(int i = 0; i < n; i++) {
        ll l, m;
        cin >> l >> m;
        a[i] = {m, l};
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    ll curr_end = 0;
    for(int i = 0; i < n; i++) {
        
        if(a[i].second >= curr_end){
            ans++;
            curr_end = a[i].first;
        } 
    }
    cout << ans << endl;
}