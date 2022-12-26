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

    int dp[n + 1][n + 1];

    char v[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if(i == n && j == n) {
                    dp[i][j] = (v[i][j] == '*') ? 0 : 1;
            }
            else {
                    int op1 = (i == n) ? 0 : dp[i + 1][j];
                    int op2 = (j == n) ? 0 : dp[i][j + 1];

                    dp[i][j] = (op1 + op2) % mod;
                    if(v[i][j] == '*') dp[i][j] = 0;
            }
        }
    }
    cout << dp[1][1];
}