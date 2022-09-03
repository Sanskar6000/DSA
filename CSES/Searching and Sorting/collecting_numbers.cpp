//Intuition: For a(0.....i) it will have the sum from a[0] to a[0] + a[1] + ..... + a[i]
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(a.begin(), a.end());
    ll ans = 1, curr = a[0].second;
    for(int i = 0; i < n; i++) {
        if(a[i].second < curr) ans++;
        curr = a[i].second;
    }
    cout << ans;
}