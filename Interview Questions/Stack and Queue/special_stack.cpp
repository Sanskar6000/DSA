  	//We will be using 2 stacks
	//Auxillary stack will only insert if given value is less than its top
	//Auxillary stack will only remove if minimum element is being removed

	stack<int> s1;
    stack<int> s2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s2.empty() || val <= getMin()) s2.push(val);
        s1.push(val);
    }
    
    void pop() {
        if(s1.top() == getMin()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }