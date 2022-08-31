//Using merge technique of merge sort
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end
        int i = m - 1, j = n - 1;
        while(j != -1 && i != -1) {
            cout << " i " << i << " j " << j << endl;
            if(nums1[i] > nums2[j]) {
                nums1[i + j + 1] = nums1[i];
                i--;
            }
            else {
                nums1[i + j + 1] = nums2[j];
                j--;
            }
        }
        while(j != -1) {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }