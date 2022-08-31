//Applying Cyclic sort
int findDuplicate(vector<int>& nums) {
    int i = 0, n = nums.size();
    while(i < n) {
        while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
        i++;
    }
    return nums[n - 1];
}