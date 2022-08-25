int paths(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return grid[i][j];
        
        if(i < 0 || j < 0) return 10000;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int l = grid[i][j] + paths(grid, i - 1, j, dp);
        
        int r = grid[i][j] + paths(grid, i, j - 1, dp);
        
        return dp[i][j] = min(l, r);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return paths(grid, m - 1, n - 1, dp);
    }