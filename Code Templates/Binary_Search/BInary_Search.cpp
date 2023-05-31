bool isgood(int mid, vector<int> &A, int B) {
    int sum = 0;
    for(auto i : A) {
        if(i - mid > 0) sum += (i - mid);
    }
    
    return (sum >= B);
}

int solve(vector<int> &A, int B) {
    int n = A.size();
    int l = 0, r = 1e6 + 10, ans = l;
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(isgood(mid, A, B)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    return ans;
}