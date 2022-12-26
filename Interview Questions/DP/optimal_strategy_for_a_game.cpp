long long f(int arr[], int n, int i, int j, vector<vector<long long>> &dp) {
        if(i > j || i < 0 || j < 0 || i >= n || j >= n) return 0;
        if(j - i == 0) return arr[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long op1 = arr[i] + min(f(arr, n, i + 2, j, dp), f(arr, n, i + 1, j - 1, dp));
        
        long long op2 = arr[j] + min(f(arr, n, i + 1, j - 1, dp), f(arr, n, i, j - 2, dp));
        
        return dp[i][j] = max(op1, op2);
    }
    
    //Draw the table...Will fill the table Diagonal Wise
    long long maximumAmount(int arr[], int n){
        
        vector<vector<long long>> dp(n, vector<long long> (n, 0));
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++) {
                if(j - i == 0) {
                    dp[i][j] = arr[i];
                }
                else {
                    long long op1 = (i + 2 <= j) ? dp[i + 2][j] : 0;
                    
                    long long op2 = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                    
                    long long op3 = (i <= j - 2) ? dp[i][j - 2] : 0;
                    
                    dp[i][j] = max(arr[i] + min(op1, op2), arr[j] + min(op2, op3));
                }
            }
        }
        
        return dp[0][n - 1];
    }