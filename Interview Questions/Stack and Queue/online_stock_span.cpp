//We will push {element, value} in stack
stack<pair<int, int>> s;
StockSpanner() {
        
}
    
int next(int price) {
    int count = 1;
        
    while(!s.empty() && s.top().first <= price) {
        count += s.top().second;
        s.pop();
    }
        
    s.push({price, count});
        
    return count;
}