//Sort both the arrays... compare 1st arrival to oth departure. If less then platforms ++ and increase arrival else platforms-- and j++

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
        
    int plat = 1, ans = 1;
    int i = 1, j  = 0;
        
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            plat++;
            i++;
        }
        else {
            plat--;
            j++;
        }
        ans = max(ans, plat);
    }
    return ans;
}