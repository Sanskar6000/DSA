//!Best Approach:
//!Understanding States
/*
Consider string aacabdkacaa
now state(start, end) reprsents a substring
consider state(0, 11) -> aacabdkacaa
consider state(0, 10) -> aacabdkaca
consider state(1, 11) -> acabdkacaa

!State Transitions
now states where start == end -> true
state(0, 0) = state(5, 5) = true if(i == j) -> true
state(0, 1) = true if(s[i] == s[j])
state(0, 3) = true if(s[i] == s[j]) && state(1, 2) -> true
!State Transitions

Now, state(start, end) will be true only and only if s[start] == [end] && state(start + 1, end - 1) = true
*/
string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    dp[i][j] = true;
                }
            }
        }
        int max_length = 1, start_index = 0;
        for(int end = 0; end < n; end++) {
            for(int start = 0; start <= end; start++) {
                if(start == end) {
                    dp[start][end] = true;
                }
                else {
                     if(s[start] == s[end]) {
                        if(end - start == 1 || dp[start + 1][end - 1] == true) {
                            dp[start][end] = true;
                            if(end - start + 1 > max_length) {
                            max_length = end - start + 1;
                            start_index = start;
                        }
                    } 
                } 
                }
               
            }
        }
        
    
        // return " ";
        return s.substr(start_index ,max_length);
    }


//?Approach based on Longest common substring
// 1. This problem can be interpreted as finding longest common substring of string s and reverse of it, say r. 
// However, there is catch when reverse of a substring occurs in string s (for example, string aaca occurs in string aacabdkacaa)
// 2. This situation can be tackled by checking if index i in string s is equivalent to index j in string r if 
// the string has not been reversed.
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
            
        int maxLength = 0, maxEnd = 0;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                // Storing longest common substring in dp Array
                if(s[i - 1] == r[j - 1]){
                  dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
				//Code to check i and j
                if(dp[i][j] > maxLength) {
                    if(i - dp[i][j] == s.size() - j) {
                        maxLength = dp[i][j];
                        maxEnd = i;
                    }
                }
            }
        }
        return s.substr(maxEnd - maxLength, maxLength);
    }