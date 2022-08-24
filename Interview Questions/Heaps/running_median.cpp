//Idea is to use Max Heap and Min Heap
//Max Heap -> Priority Queue
//Min Heap -> Priority Queue (greater <int>)

// Algorithm
//If number is less than top element of max heap then add it to max heap
//else add it to min heap
//If size of max heap is 2 more than min heap, then add top element of max heap to min heap
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
    
MedianFinder() {
        
}
    
void addNum(int num) {
    if(max_heap.size() == 0 || max_heap.top() >= num) {
        max_heap.push(num);
    }
    else {
        min_heap.push(num);
    }
        
    //if there are more than two elements difference
    if(max_heap.size()  > 1 + min_heap.size()) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
    else if(max_heap.size() < min_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
        
}
    
double findMedian() {
    if(max_heap.size() == min_heap.size()) {
        return (((double)max_heap.top() + min_heap.top())/2.0);
    }
    else {
        return (double)max_heap.top();
    }
}