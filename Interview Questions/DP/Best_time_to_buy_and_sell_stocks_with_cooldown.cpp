  int maxPs(vector<int>& prices, int ind, int canBuy, vector<vector<int>> &dp) {
        
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        if(canBuy) {
            //Buying
            int l = -prices[ind] + maxPs(prices, ind + 1, 0, dp);
            
            //not Buying
            int r = 0 + maxPs(prices, ind + 1, 1, dp);
            
            return dp[ind][canBuy] = max(l, r);
        }
        else {
            //Selling
            int l = +prices[ind] + maxPs(prices, ind + 2, 1, dp);
            
            //Not Selling
            int r = 0 + maxPs(prices, ind + 1, 0, dp);
            
            return dp[ind][canBuy] = max(l, r);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return maxPs(prices, 0, 1, dp);
    }