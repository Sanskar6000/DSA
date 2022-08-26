void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
         
    int leftArray[leftSize];
    int rightArray[rightSize];
         
    for(int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }
         
    for(int i = 0; i < rightSize; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }
         
    int l = 0, r = 0;
    int m = left;
         
    while(l < leftSize && r < rightSize) {
        if(leftArray[l] <= rightArray[r]) {
            arr[m] = leftArray[l];
            l++;
        }
        else {
            arr[m] = rightArray[r];
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
}
    

void mergeSort(int arr[], int l, int r)
{
    if(l < r) {
        int mid = (l + r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}