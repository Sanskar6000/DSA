// Given two strings, S of length m and T of length n, find a longest string which is substring of both S and T.
//Let's Find out Longest common sub-string
    string reverse(string s) {
        int len = s.size();
        string r = "";
        for(int i = 0; i < len; i++) {
            r += "$";
        }
        for(int i = len - 1; i >= 0; i--) {
            r[i] = s[len - 1 - i];
        } 
        return r;
    }
    
    string longestPalindrome(string s) {
        string r = reverse(s);
        int n = s.size();
        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
     
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                // Storing longest common substring in dp Array
                if(s[i - 1] == r[j - 1]){
                  dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
            }
        }
        
        // for largest substring searching through the dp array
        int len = -1, ind = -1;
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                 if(dp[i][j] > len) {
                len = dp[i][j];
                ind = i - 1;
            }
            }
           
        }
        // for(int i = 0; i < n + 1; i++) {
        //     for(int j = 0;  j < n + 1; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << len << endl;
        //Construct a string
        string a = "";
        if(len == 0) a += s[0];
        for(int i = 0; i < len; i++) {
            a += "$";
        }
        cout << ind << endl;
        for(int i = len - 1; i >= 0; i--) {
            a[i] = s[ind--];
        }
        // string e = s[0];
        // if(a.size() == 0) return e;
        return a;
    }