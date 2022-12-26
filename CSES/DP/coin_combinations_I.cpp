#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(auto c : a) {
            if(i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= mod;
            } 
        }
    }

    cout << dp[x];
}