  void solution(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < arr.size() ;i++) {
            if(i > ind && arr[i - 1] == arr[i]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            solution(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solution(0, target, candidates, ans, ds);
        return ans;
    }