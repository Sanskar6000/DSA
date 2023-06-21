/*
Leetcode 1755
len(array) - 40, array[i] <= 1e9, find maximum subset sum having sum <= s, where s <= 1e18
1. Divide the array in two equal parts
2. Find all possible subset sums
3. arr1 = [0, 3, 5, 8], arr2 = [-1, 0, 6, 7] 
TC - O(N* 2^(n/2))   
*/

