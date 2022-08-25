//Partition DP
/*Given a sequence of matrices, find the most efficient way to multiply these matrices together.
    @No need to actually perform the multiplication
    @Just decide the order

    A1 A2 A3 A4

    (A1) (A2 A3 A4)
    (A1 A2) (A3 A4)
    (A1 A2 A3) (A4)
    (A1) (A2 A3) (A4)
    (A1(A2(A3 A4)))

    A1 -> 2 * 3
    A2 -> 3 * 4

    New Matrix formed size -> 2 * 4
    Cost of Multiplication -> 2 * 3 * 4
*/

int mcm(int arr[], int i, int j, vector<vector<int>> &dp) {
        
    //Size of Chain is 1. 
    //Hence, Number of operations will be 0
    if(i == j) return 0;
        
    if(dp[i][j] != -1) return dp[i][j];
        
    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        //We will solve for left size and then right side
        int temp = mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }
        
    return dp[i][j] = ans;
}
    
int matrixMultiplication(int N, int arr[])
{   
    //We will pass a chain of matrices to be multiplied
    //States i and j
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return mcm(arr, 1, N - 1, dp);
}
