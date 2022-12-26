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

    //Remember Base Case
    int editDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                //If first string is empty
                if(i == 0) {
                    dp[i][j] = j;
                }
                else if(j == 0) {
                    dp[i][j] = i;
                }
                else if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int op1 = dp[i - 1][j - 1];
                    int op2 = dp[i - 1][j];
                    int op3 = dp[i][j - 1];
                    dp[i][j] = 1 + min(op1, min(op2, op3));
                }
            }
        }
        return dp[n][m];
    }