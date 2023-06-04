class Solution {
public:
    int dp[1001][1001][2];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, bool continuous) {
        // Base case: If we reach the end of either array, return 0.
        if(i == nums1.size() || j == nums2.size())
            return 0;
 
        // If the solution for the current state has already been computed, return it.
        if(dp[i][j][continuous] != -1)
            return dp[i][j][continuous];
 
        int ans = 0;
        if(continuous) {
            // If we are in a continuous substring and the current elements are equal,
            // increment the length of the substring and move to the next elements.
            if(nums1[i] == nums2[j])
                dp[i][j][continuous] = 1 + solve(i + 1, j + 1, nums1, nums2, true);
            else
                dp[i][j][continuous] = 0; // The substring is broken, set length to 0.
        }
        else {
            // If we are not in a continuous substring, we have three choices:
            // 1. Move to the next element in nums1 and keep nums2 as is.
            // 2. Move to the next element in nums2 and keep nums1 as is.
            // 3. If the current elements are equal, start a new continuous substring.
			int ans = 0;
            ans = max({
                ans,
                solve(i + 1, j, nums1, nums2, continuous),
                solve(i, j + 1, nums1, nums2, continuous)
            });
            if(nums1[i] == nums2[j])
                ans = max(ans, 1 + solve(i + 1, j + 1, nums1, nums2, true));
 
            dp[i][j][continuous] = ans;
        }
        return dp[i][j][continuous];
    }
 
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size(), m = nums2.size();
       memset(dp, -1, sizeof(dp)); // Initialize the dp array with -1.
       return solve(0, 0, nums1, nums2, false); // Call the solve function to find the length of the longest common substring.
    }
};