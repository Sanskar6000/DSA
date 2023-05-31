/*
Given a list of cities and distances between each pair of cities, what is the shortest
possible route that visits each city and returns to the oriqin city
*/
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif
 
#define int long long int
 
int n;
int cost[21][21];
int dp[21][(1 << 21)];
 
int helper(int i, int mask) {
    if(mask == 0) return cost[i][0];
 
    if(dp[i][mask] != -1) return dp[i][mask];
 
    int ans = INT_MAX;
 
    for(int j = 0; j < n; j++) {
        if((mask & (1 << j)))
                ans = min(ans, cost[i][j] + helper(j, (mask^(1 << j))));
    }
 
    return dp[i][mask] = ans;
}
 
void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> cost[i][j];
 
    cout << helper(0, (1 << n)  - 1) << '\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}