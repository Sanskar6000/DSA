//Creating a Heap

//Heapify: TC -> O(N)
// Swapping from last element with children
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if(l <= n && a[l] > a[largest]) {
        largest = l;
    }
    if(r <= n && a[r] > a[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(a[i], a[largest]);
        swap(a[n], a[largest]);
    }
}