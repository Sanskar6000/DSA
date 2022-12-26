int maxLen(vector<int>&A, int n)
    {   
        int ans = 0;
        int pf = 0;
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            pf += A[i];
            if(pf == 0) {
                ans = max(ans, i + 1);
            }
            else {
                if(m.find(pf) == m.end()) {
                    m.insert({pf, i});
                }
                else {
                    ans = max(ans, i - m[pf]);
                }
            }
        }
        
        return ans;
    }