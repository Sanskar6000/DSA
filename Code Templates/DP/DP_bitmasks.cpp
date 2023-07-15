/*
Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that 
may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one 
worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is 
minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20
*/

/*
Brute force will take n! permultations to check
dp[i, mask] = min cost to assign to people from i to n such that people are represented by mask available
final ans => dp(1, 111111...1111)

dp[i, mask] = Cij + dp[i + 1, mask|turn off jth bit] for valid j -> jth bit is on

Space Complexity: O(N * 2^N)
Time Complexity: O(N^2 * 2^N)
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
    if(i == n) return 0;

    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = INT_MAX;

    for(int j = 0; j < n; j++) {
        if(mask & (1 << j))
            ans = min(ans, cost[j][i] + helper(i + 1, (mask | (1 << j)))); //xor or or? if my mask is 11111 I need xor to make it visited
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