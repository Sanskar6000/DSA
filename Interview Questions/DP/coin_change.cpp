int INF = 1e9;
int total(vector<int>& coins, int ind, int amount, vector<vector<int>> &dp) {
        
    if(ind == 0) {
        if(amount % coins[ind] == 0) return amount/coins[ind];
        return INF;
    }
        
    if(dp[ind][amount] != -1) return dp[ind][amount];
        
    int notPick = 0 + total(coins, ind - 1, amount, dp);
        
    int pick = INF;
    if(coins[ind] <= amount) pick = 1 + total(coins, ind, amount - coins[ind], dp);
        
    return dp[ind][amount] = min(notPick, pick);
}
    
int coinChange(vector<int>& coins, int amount) {
        
    int n = coins.size();
    // Memoize ind and amount
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
    //Passing ind = n - 1, amount = amount
    if(total(coins, n - 1, amount, dp) == INF) return -1;
    return total(coins, n - 1, amount, dp);
}