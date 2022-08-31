 void sortColors(vector<int>& nums) {
        //Dutch National Flag Algorithm
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        while(mid < nums.size()) {
            switch(nums[mid]){
                    
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[hi--], nums[mid++]);
                    break;
                    
            }
        }
        }