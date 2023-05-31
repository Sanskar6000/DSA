//Finding most efficient way to multiply matrices together ABC -> (AB)C & A(BC)
//Dividing the array/string on indices [0, 1, ....., n - 1] and solving for all subproblems
int mcm(vector<int> &a, int l, int r, int n) {
    if(l < 0 || l >= n || r < 0 || r >= n) return -1;
    
    int ans = INF;
    for(int i = l; i < r; i++) {
        int left = mcm(a, l, i, n);
        int right = mcm(a, i + 1, r, n);
        ans = min(left, right);
    }

    return ans;
} 

(P)a*b * (Q)b*c => (R)a*c ===> Cost: a * b * c

int dp[N][N];

int mcm(vector<int> &a, int l, int r) {
    if(l >= r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int res = INT_MAX;
    int temp;
    for(int k = l; k < r; k++) {
        temp = mcm(a, l, k) + mcm(a, k + 1, r) + a[l] * a[k] * a[r];

        res = min(res, temp);
    }

    return dp[l][r] = res;
}

//Ques: Scramble String (Leetcode)