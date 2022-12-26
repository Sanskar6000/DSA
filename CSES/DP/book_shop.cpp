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

    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i] = (c[j] > i) ? dp[i] : max(dp[i], p[j] + dp[i - c[j]]);
        }
    }
    for(auto i : dp) cout << i << " ";
    cout << "\n";
    cout << dp[x];
    
}