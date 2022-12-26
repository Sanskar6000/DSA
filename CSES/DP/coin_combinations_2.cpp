#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;
    vector<int> a(N + 1);
    for(int i = 1; i <= N; i++) cin >> a[i];

    int dp[N + 1][X + 1];

    for(int i = 1; i <= N; i++) {
        for(int x = 0; x <= X; x++) {
            if(x == 0) {
                dp[i][x] = 1;
            }
            else {
                int l = (i == 1) ? 0 : dp[i - 1][x];
                int r = (a[i] > x) ? 0 : dp[i][x - a[i]];
                dp[i][x] = (l + r) % mod;
            }
        }
    }
    cout << dp[N][X];
} 