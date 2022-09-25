    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
            
        int ans = 0;
        
        int max_length = 1, start_index = 0;
        for(int end = 0; end < n; end++) {
            for(int start = 0; start <= end; start++) {
                if(start == end) {
                    dp[start][end] = true;
                    ans++;
                }
                else {
                     if(s[start] == s[end]) {
                        if(end - start == 1 || dp[start + 1][end - 1] == true) {
                            dp[start][end] = true;
                            ans++;
                    } 
                } 
                }
               
            }
        }
        
    
        // return " ";
        return ans;
    }