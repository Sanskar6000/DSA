MyStack() {
        
    }
queue<int> q;
    
//Push time complexity will be O(1)
void push(int x) {
    q.push(x);
    int size = q.size() - 1;
    for(int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}
    
int pop() {
    if(q.empty()) return -1;
    int ans = q.front();
    q.pop();
    return ans;
}
    
int top() {
    return q.front();
}
    
bool empty() {
    return q.empty();
}