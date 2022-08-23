//While pushing in stack two we have to check if stack2 is empty
//If stack two is not empty() then front element will be present in stack2
    
stack<int> s1, s2;
MyQueue() {
        
}
    
void push(int x) {
    s1.push(x);
}
    
int pop() {
    peek();
    int t = s2.top();
    s2.pop();
    return t;
}
    
int peek() {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();    
        }
    }
    return s2.top();
}
    
bool empty() {
    //Both must be empty
    return s1.empty() && s2.empty();
}