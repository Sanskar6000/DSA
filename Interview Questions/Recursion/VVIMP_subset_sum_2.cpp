//!!Warnng Don't pass temporary array by reference
//Time Complexity: O( 2^n *(k log (x) )). 2^n 
void subsets(int ind, int n, vector<int>& nums, set<vector<int>> &ans, vector<int> temp) {
        
    if(ind == n) {
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
    }
        
    //Pick
    temp.push_back(nums[ind]);
    subsets(ind + 1, n, nums, ans, temp);
    temp.pop_back(); //Backtracking step

    subsets(ind + 1, n, nums, ans, temp);
}
    
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //Pass ind, size, set
    set<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
        
    subsets(0, n, nums, ans, temp);
        
    vector<vector<int>> a;
    for(auto vec : ans) {
        a.push_back(vec);
    }
        
    return a;
}

//Optimised Solution
/*
1. Sort the array
2. Skip duplicates

TC - 2^N * k
*/

//?Every time we will call a recursive function
//?We will generate lists of size 0, 1, 2,......., n 
//Carry an empty data structure
//Generate a list of size one
vector<vector<int>> ans;
    
void f(int ind,vector<int> &nums, vector<int> &temp) {
    ans.push_back(temp);
    for(int i = ind; i < nums.size(); i++) {
        if(i != ind && nums[i] == nums[i - 1]) continue;
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