int dp[5001][5001];
int solve(int i, int j, string &s1, string &s2) {

    if(i == s1.size() || j == s2.size()) {
        return max(s2.size() - j, s1.size() - i);

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i + 1][j + 1];

        int op1 = 1 + solve(i, j + 1, s1, s2);
        int op1 = 1 + solve(i + 1, j, s1, s2);
        int op1 = 1 + solve(i + 1, j + 1, s1, s2);

        return dp[i][j] = min({op1, op2, op3});
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    solve(0, 0, s1, s2);
}