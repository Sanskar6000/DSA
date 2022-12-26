//A form of Longest Common Subsequnce
//We will pass index with prev ind
//and we will take element only if current is greater than prev
//Note: Take a look at Take Operation how it is implemented

//Printing LISflip
int length(vector<int>& nums, int ind, int prev, vector<vector<int>> &dp) {
        
    if(ind == nums.size()) return 0;
        
    if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
    //Not Take
    int l = 0 + length(nums, ind + 1, prev, dp);
        
    //Take (IMP) At last we, need to return max(l, r) hence computing before hand
    if(prev == -1 || nums[ind] > nums[prev]) l = max(l, 1 + length(nums, ind + 1, ind, dp)); 
        
    return dp[ind][prev + 1] = l;
}
    
int lengthOfLIS(vector<int>& nums) {
        
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        
    return length(nums, 0, -1, dp);
}

//O(N^2) Solution
int longestSubsequence(int n, int a[])
{
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] =  max(dp[i], 1 + dp[j]);
            }
        }
    }
}

    int ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
        
    return ans;
}

//O(NlogN) Solution
