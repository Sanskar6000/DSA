//O(n^3)
//Finding most efficient way to multiply matrices together ABC -> (AB)C & A(BC)
//Dividing the array/string on indices [0, 1, ....., n - 1] and solving for all subproblems
int mcm(vector<int> &a, int l, int r, int n) {
    if(l < 0 || l >= n || r < 0 || r >= n) return -1;
        
    /* The loop condition for(int i = left; i < right; i++) is used instead of for(int i = left; i <= right; i++) 
    in order to divide the range [left, right] into two subranges [left, i] and [i+1, right].
    By using i < right as the loop condition, it ensures that i will take values up to right - 1, allowing the range 
    to be split into two non-empty subranges. If i were allowed to be equal to right, then one of the subranges would become 
    empty, which is not desirable in this context. */

    int ans = INF;
    for(int i = l; i < r; i++) {
        int left = mcm(a, l, i, n);
        int right = mcm(a, i + 1, r, n);
        ans = min(left, right);
    }

    return ans;
} 

int main() {
    int arr[4] = {2, 3, 4, 5};
    return mcm(0, n - 1);
}


//Matrix Chain Multiplication
// a * b * c * d -> choose b and c -> or array becomes -> a * (b * c) * d -> a * e * d
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