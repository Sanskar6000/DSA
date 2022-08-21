  //we have to take three cases

  int minDistances(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        
        //Base Case
        if(j < 0) return i + 1;
        if(i < 0) return j + 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]) return dp[i][j] = 0 + minDistances(word1, word2, i - 1, j - 1, dp);
        
        //Insertion Case
        int l = 1 + minDistances(word1, word2, i, j - 1, dp);
        
        //Deletion Case
        int r = 1 + minDistances(word1, word2, i - 1, j, dp);
        
        //Replacement Case
        int m = 1 + minDistances(word1, word2, i - 1, j - 1, dp);
        
        return dp[i][j] = min(min(l, r), m);
    }