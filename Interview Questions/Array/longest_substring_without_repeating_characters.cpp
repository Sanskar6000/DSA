 int lengthOfLongestSubstring(string s) {
        map<int, int> m;
        int l = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            while(m.count(s[i])) {
               m[s[l]]--;
               if(m[s[l]] == 0) m.erase(s[l]);
               l++;
            }
            m[s[i]]++;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }