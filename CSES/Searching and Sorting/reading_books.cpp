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
    vector<ll> a(n);
    ll sum = 0, maxi = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxi = max(maxi, a[i]);
    } 

    cout << max(sum, 2*maxi);
}