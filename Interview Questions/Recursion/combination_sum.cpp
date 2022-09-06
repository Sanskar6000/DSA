void solution(vector<int> &candidates, int n, vector<vector<int>> &ans, vector<int> ds, int target, int ind) {
        if(ind == n) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            solution(candidates, n, ans, ds, target - candidates[ind], ind);
            ds.pop_back();
        }
        
        solution(candidates, n, ans, ds, target, ind + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = candidates.size();
        
        solution(candidates, n, ans, ds, target, 0);
        
        return ans;
    }