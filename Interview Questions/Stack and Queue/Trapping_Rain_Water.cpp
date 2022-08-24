//Use two pointers left and right
//IMP!!!!!!!!!!!!!
//Start filling from lower part of both ends
//Je lower height chi range ahe ti bharat janaar
 int trap(vector<int>& height) {
        //Start filling from lower part of both ends
        int n = height.size();
        int low = 0, high = n - 1;
        int max_low = 0, max_high = 0, ans = 0;
        while(low <= high) {
            if(height[low] <= height[high]) {
                if(height[low] >= max_low) {
                    max_low = height[low];
                }
                else {
                    ans += max_low - height[low];
                }
                low++;
            }
            else {
                if(height[high] >= max_high) {
                    max_high = height[high];
                }
                else {
                    ans += max_high - height[high];
                }
                high--;
            }
        }
        
        return ans;
    }
