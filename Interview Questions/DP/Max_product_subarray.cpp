 //Take vector of vector, store arrays by boundaring zeroes 


 int maxProduct(vector<int>& nums) {
        vector<vector<int>> a;
        
        vector<int> temp;
        int numZeroes = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) temp.push_back(nums[i]);
            if(nums[i] == 0) {
                numZeroes++;
                if(temp.size() != 0) a.push_back(temp);
                temp.clear();
            }
            
        }
        if(temp.size() != 0) a.push_back(temp);
        
        
        int ans = INT_MIN;
        for(auto v : a) {
            int numNeg = 0, temp = 1;
            for(int i = 0; i < v.size(); i++) {
                if(v[i] < 0) numNeg++;
                temp *= v[i];
            }
            int l = 1, r = 1;
            if(v.size() > 1 && numNeg != 0 && numNeg % 2) {
                int i = 0;
                do {
                    l *= v[i];
                }
                while(v[i++] > 0);
                
                int j = v.size() - 1;
                do {
                    r *= v[j];
                }
                while(v[j--] > 0);
                
                temp /= max(l, r);
            }
            ans = max(ans, temp);
        }
        if(ans < 0 && numZeroes > 0) return 0;
        return ans;
    }