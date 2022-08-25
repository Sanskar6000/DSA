//Learm how to declare a comp function in priority queue
class comp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        //We are taking account of tree representation of heap
        return a.second < b.second;
    }  
};
    
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }
        
    //Min_heap
    priority_queue<pair<int, int>, vector<pair<int, int>> ,comp> pq;
    for(auto p : m) {
        pq.push(p);
    }
            
    vector<int> ans;
    while(k--) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
        
    return ans;
}