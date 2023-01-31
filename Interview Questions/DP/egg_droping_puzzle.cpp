// Approach 1: Tries is N(starting from the bottom)

/* 
Approach 2: Breaking N into B parts lets say
then dropping the egg in parts will give us TC = (N/B + B)
Differentiating gives us B = root(N)
Tries -> 2 * root(N)
*/

/*
Approach 3:
If we throw an egg from a ith floor:
Case 1: It breaks
then we will check for x - 1 floors below us
Case 2: It doesn't break
then we will check for n - x floors above us
Thus, we need to take the worst case of both the scenarios
& we need to minimise for all possible x(s)'

f(n, e) = min(x = 1 -> n - 1)(max(f(n - x, e), f(x - 1, e - 1)) + 1));

*/

// f(n, e) = min(x = 1 -> n - 1)(max(f(n - x, e), f(x - 1, e - 1)) + 1));
    int twoEggDrop(int n) {
        //Base Case
        int dp[n + 1][2 + 1];
        
        //For first floor it will be always 1
        dp[1][1] = dp[1][2] = 1;
        //If one egg remains, tries will be n
        for(int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }
        
        //Iterating for floors staring at 2nd floor
        for(int i = 2; i <= n; i++) {
            //Eggs will be 2 only
            for(int e = 2; e <= 2; e++) {
                dp[i][e] = INT_MAX;
                //For instance i = 3, we will check for 2 & 3 floors
                for(int x = 2; x <= i; x++) {
                    int temp = max(dp[i - x][e], dp[x - 1][e - 1]) + 1;
                    if(temp < dp[i][e]) dp[i][e] = temp;
                }
            }
        }
        
        //Solution for nth floor and number of eggs 2
        return dp[n][2];
    }