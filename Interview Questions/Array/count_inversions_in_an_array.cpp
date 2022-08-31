int ans[];

int merge(int arr[], int left, int mid, int right)
{        
    int i, j, k;
    int inv_count = 0;
    
    i = left;//index for resultant array
    j = mid;
    m = 0;//Index of resultant merged array  

    while(i <= mid - 1 && j <= right) {
        if(arr[i] <= arr[j]) {
            arr[m] = leftArray[l];
            l++;
        }
        else {
            arr[m] = rightArray[r];
            inv_count += (mid - 1);
            r++;
        }
        m++;
    }
         
    while(l < leftSize) {
        arr[m] = leftArray[l];
        l++;
        m++;
    }
         
    while(r < rightSize) {
        arr[m] = rightArray[r];
        r++;
        m++;
    }

    return inv_count;
}
    

int mergeSort(int arr[], int l, int r)
{   
    int mid, inv_count = 0;
    if(l < r) {

        mid = (l + r)/2;

        inv_count += mergeSort(arr, l, mid);
        inv_count += mergeSort(arr, mid + 1, r);

        inv_count += merge(arr, l, mid, r);
    }
    return inv_count;
}