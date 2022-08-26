//Until stack becomes empty, holds all the values in a function call
//Whe stack becomes empty, insert elements in a sorted order

void insert(stack<int> &s,int &element) {
    if(s.empty() || s.top() < element) {
        s.push(element);
    }
    else {
        int temp = s.top();
        s.pop();
        insert(s, element);
        s.push(temp);
    }
}

void SortedStack :: sort()
{
   if(!s.empty()) {
       int temp = s.top();
       s.pop();
       sort();
       insert(s, temp);
   }
}