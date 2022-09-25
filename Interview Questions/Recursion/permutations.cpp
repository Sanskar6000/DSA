//We will be swapping 0 with 0 then 0 with 1 .....
//swapping 1 with 1, 1 with 2 and so on.....
void solution(int ind, int n, vector<vector<int>> &ans, vector<int> &nums) {
    if(ind == n) {
        ans.push_back(nums);
        return;
    }
        
    for(int i = ind; i < n; i++) {
        swap(nums[ind], nums[i]);
        solution(ind + 1, n, ans, nums);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    solution(0, n, ans, nums);
    return ans;
}