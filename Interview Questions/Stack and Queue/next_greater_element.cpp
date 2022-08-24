//Use a Map and Stack and start from end (because stack will be empty initially)

  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        stack<int> s;
        
        for(int i = nums2.size() - 1; i >= 0; i--) {
            
            while(!s.empty() && s.top() < nums2[i]) {
                s.pop();
            }
            
            //Next greater of last element
            if(s.empty()) {
                m[nums2[i]] = -1;
            }
            else {
                m[nums2[i]] = s.top();
            }
            
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }
        
        return ans;
    }