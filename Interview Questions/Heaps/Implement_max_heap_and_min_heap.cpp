//Min Heap: Key is present at the root node and is less than or equal to all the keys present at all of its children
//Max Heap(priority Queue): Key is present at the root node and is more than or equal to all the keys present at all of its children

// Heap is complete binary tree that satisfy's heap's property
// Max Heap -> Children will be always less than root

/* We will denote heap as a array
       50
       / \
      /   \  
    40    45
    /\     /\
   /  \   /  \ 
  30  20 35 10          

  Node -> i
  parent(i) -> floor(i/2)
  left_child(i) -> 2*i
  right_children(i) -> 2*i + 1  

*/

/* Implementation (1 indexing) */

//Inserting element in heap (logN time) 
//Insert new value at the end then find Parent and swap the given value
void insert(int arr[], int n, int value) {
    n = n + 1;
    arr[n] = value;
    int i = n;
    while(i > 1) {
        int parent = floor(i/2);
        if(a[parent] < a[i]) {
            swap(a[parent], a[i]);
            i = parent;
        }
        else {
            return;
        }
    }
}

//Deleting element in heap (Deleting Root Only!!!!!!!!!!)
//Delete root, change position of last node to first node, then swapping
//Heapify
void delete(int arr[], int n) {
    //reassign first node to last node
    a[1] = a[n];
    n = n - 1;
    int i = 1;
    while(i < n) {
        int left = arr[2 * i];
        int right = arr[2 * i + 1];

        int larger = left > right ? 2 * i: 2 * i + 1;

        if(arr[i] < arr[larger]) {
            swap(arr[i], arr[larger]);
            i = larger;
        }
        else {
            return;
        }
    }
}