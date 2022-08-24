//Kth largest element, We will use priority queue (min heap) time will be O(N*logN)
//It is called min head because we can remove minimum element using pop() operation

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        
        return pq.top();
}

//For, O(N) time Complexity
//We will use Pivot technique