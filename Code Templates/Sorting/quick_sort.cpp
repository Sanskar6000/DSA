// The average time complexity of quick sort is O(N log(N)). Quick Sort is a sorting algorithm that works using 
// the Divide and Conquer approach. It chooses a pivot and 
// places it in its correct position in the sorted array and partitions the smaller elements to its left and
// the greater ones to its right.

//Pick a Pivot and elements smaller than pivot will be on the left of pivot and elements larger will be on the right of pivot

//Time Complexity Analaysis
//1. Always partition in middle -> O(N * logN) --> Pivot should be median
//2. If list is already sorted -> Partition will be happening in the beginning of list -> O(N^2)
//3. Select Middle element as Pivot, Select Random element as Pivot
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
           while(pivot >= arr[i] && i < high) {
               i++;
           }
           while(pivot < arr[j] && j > low) {
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