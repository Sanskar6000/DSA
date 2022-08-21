//Take LCS but while taking skip one element

int robbers(vector<int> &nums, int i, vector<int> &dp) {
        
        if(i == -1) return 0;
        if(i == 0) return nums[0];
        
        if(dp[i] != -1) return dp[i];
        
        int take = nums[i] + robbers(nums, i - 2, dp);
        int notTake = 0 + robbers(nums, i - 1, dp);
        
        return dp[i] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        //Also carry Adjacent
        return robbers(nums, n - 1, dp);
    }