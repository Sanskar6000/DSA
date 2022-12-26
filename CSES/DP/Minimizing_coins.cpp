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

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - a[j] < 0) continue;
            dp[i] = min(dp[i] ,1 + dp[i - a[j]]);
        }
    }
    // for(auto i : dp) cout << i << " ";
    // cout << "\n";
    if(dp[x] == INF) cout << -1;
    else cout << dp[x];
}