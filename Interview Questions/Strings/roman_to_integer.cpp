int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
                          {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        for(int i = 0; i < s.size(); ) {
            if(i + 1 < s.size()) {
                if(m[s[i + 1]] <= m[s[i]]) {
                ans += m[s[i]];  
                i += 1;
                } 
            else {
              ans += m[s[i + 1]] - m[s[i]];
              i += 2;
            } 
            }
            else {
                ans += m[s[i]];
                break;
            }
        } 
        cout << m[s[0]];
        return ans;
    }