//For finding longest consecutive sequence in O(n) time we will use unordered_set/unordered_map which has searching time of O(1)
//Internally implemented using a hash table hence O(1)
 int longestConsecutive(vector<int>& nums) {
        //For O(n) time, we will use unordered_map/unordered_set O(1) (Internal Implementation is using Hash Table)
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) s.insert(nums[i]);
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(s.count(nums[i] - 1)) continue;
                int curr_num = nums[i];
                int curr_streak = 1;
                
                while(s.count(curr_num + 1)) {
                    curr_num += 1;
                    curr_streak += 1;
                }
            ans = max(ans, curr_streak);
        }
        return ans;
    }