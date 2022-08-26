void quickSort(int arr[], int low, int high)
    {
        if(low < high) {
            
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    int partition (int arr[], int low, int high)
    {
       int pivot = arr[low];
       
       int i = low;
       int j = high;
       
       while(i < j) {
           while(pivot >= arr[i]) {
               i++;
           }
           while(pivot < arr[j]) {
               j--;
           }
           //If i is ahead of j
           if(i < j) {
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[low], arr[j]);
       return j;
    }