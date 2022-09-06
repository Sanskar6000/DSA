 void solution(int ind, int sum, vector<int> &ans, vector<int> &arr, int N) {
        if(ind == N) {
            ans.push_back(sum);
            return;
        }
        
        // Pick the element
        solution(ind + 1, sum + arr[ind], ans, arr, N);
        
        // Not pick the element
        solution(ind + 1, sum, ans, arr, N);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {   
        vector<int> ans;
        solution(0, 0, ans, arr, N);
        return ans;
    }