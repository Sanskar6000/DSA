	int sum(int arr[], int i, int prev, int n, vector<vector<int>> &dp) {
	    
	    if(i == n) return 0;
	    
	    if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
	    
	    //Not take
	    int l = 0 + sum(arr, i + 1, prev, n, dp);
	    
	    //take
	    if(prev == -1 || arr[prev] < arr[i]) l = max(l, arr[i] + sum(arr, i + 1, i, n, dp));
	    
	    return dp[i][prev + 1] = l;
	}

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    //Memoize
	    vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
	    
	    //Variant of LOngest Increasing subsequence
	    return sum(arr, 0, -1, n, dp);
	}  