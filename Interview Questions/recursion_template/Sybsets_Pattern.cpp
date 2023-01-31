//Carry an empty data structure
//Generate a list of size one
vector<vector<int>> ans;
    
void f(int ind,vector<int> &nums, vector<int> &temp) {
    ans.push_back(temp);
    for(int i = ind; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        f(i + 1, nums, temp);
        temp.pop_back();
    }
}
    
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;
    f(0, nums, temp);
        
    return ans;
}