vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if(B > n) return {};
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i = 0; i < B; i++) {
        m[A[i]]++;
    }
    ans.push_back(m.size());
    //two pointers
    int l = 1, r = B;
    while(r < n) {
        int prev = A[l - 1];
        int curr = A[r];
        m[prev]--;
        if(m[prev] == 0) m.erase(prev);
        m[curr]++;
        ans.push_back(m.size());
        l++; r++;
    }
    
    return ans;
}


vector<int> Solution::dNums(vector<int> &A, int B) {
    long n = A.size();
    if(B > n) return -1;
    long ans = -1;
    unordered_map<long, long> m;
    for(int i = 0; i < B; i++) {
        m[A[i]]++;
    }
    if(m.size() == B) {
        for(auto i : m) {
            ans += (long)i.second;
        }
    }
    //two pointers
    int l = 1, r = B;
    while(r < n) {
        long prev = A[l - 1];
        long curr = A[r];
        m[prev]--;
        if(m[prev] == 0) m.erase(prev);
        m[curr]++;
        if(m.size() == B && ans = -1) {
            for(auto i : m) {
                ans += (long)i.second;
            }
        }
        if(m.size() == B) ans = max(ans, ans - prev + curr);
        l++; r++;
    }
    
    return ans;
}
