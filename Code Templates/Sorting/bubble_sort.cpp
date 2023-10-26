#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                flag = false;
                swap(arr[j], arr[j + 1]);
            } 
        }
        if(flag) break;
    }
}

// Max element will be shifted to last in one pass
// flag variable to reduce my number of passes