//Finding number of digits between 0 and R such that their sum of digits is X
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int dp[101][181][2];

//NUM -> R, n -> number of digits in R, x -> required sum, tight -> tight constrained
int helper(string &num, int n, int x, bool tight) {
    if(n == 0) {
        if(x == 0) return 1;
        else return 0;
    }

    if(dp[n][x][tight] != -1) return dp[n][x][tight];

    //upperbound
    int ub = tight ? num[(num.size() - n)] - '0' : 9;
    int ans = 0;
    for(int dig = 0; dig <= ub; dig++) {
        ans += helper(num, n - 1, x - dig, (tight&(dig == ub)));
    }

    return dp[n][x][tight] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    string l = "0", r = "8465451515748462120";
    cout << helper(r, r.size(), 1, 1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}