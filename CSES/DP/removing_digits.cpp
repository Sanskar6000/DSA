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

    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int ans = INF;
        int temp = i; 
        while(temp) {
            int di = temp % 10;
            temp = temp/10;
            if(di == 0) continue;
            ans = min(ans, 1 + dp[i - di]);
        }
        dp[i] = ans;
    }

    cout << dp[n];
}