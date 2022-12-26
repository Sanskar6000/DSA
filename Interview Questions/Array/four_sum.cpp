vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Solving using 2 initial pointers and 2 pointers
        vector<vector<int>> ans;
        
        if(nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < n; j++) {
                
                int front = j + 1, back = n - 1;          
                
                while(front < back) {
                    if(nums[i] + nums[j] + nums[front] + nums[back] < target) front++;
                    else if(nums[i] + nums[j] + nums[front] + nums[back] > target) back--;
                    else {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[0] = nums[j];
                        quad[0] = nums[front];
                        quad[0] = nums[back];
                        
                        ans.push_back(quad);
                        
                        // Processing Duplicates
                        while(front < back && nums[front] == quad[2]) front++;
                        while(front > back && nums[back] == quad[3]) back--;
                    }
                }
                // Duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        
        return ans;
    }