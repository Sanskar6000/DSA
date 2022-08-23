//Idea is Simple -> We will use two Stacks. Second stack will only store minimum values
// 1) push x to the first stack (the stack with actual elements) 
// 2) compare x with the top element of the second stack (the auxiliary stack). Let the top element be y. 
// If x is smaller than y then push x to the auxiliary stack. 
// If x is greater than y then push y to the auxiliary stack.
// int Pop() // removes an element from Special Stack and return the removed element 

// pop the top element from the auxiliary stack. 
// pop the top element from the actual stack and return it. Step 1 is necessary to make sure that the auxiliary stack is also updated for future operations.
// int getMin() // returns the minimum element from Special Stack 

// Return the top element of the auxiliary stack.

void push(stack<int>& s, int a){
	  s.push(a);
}

bool isFull(stack<int>& s,int n){
    if(s.size() >= n) return true;
    return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
    if(s.size() == 0) return -1;
	int n = s.top();
	s.pop();
	return n;
}

int getMin(stack<int>& s){
	stack<int> aux;
	int mn = 1e9;
	while (!s.empty()) {
	    aux.push(s.top());
	    mn = min(mn,s.top());
	    s.pop();
	}
	while (!aux.empty()) {
	    s.push(aux.top());
	    aux.pop();
	}
	return mn;
}