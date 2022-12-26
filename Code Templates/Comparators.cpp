/*
1. Comparator functions used with sort(a.begin(), a.end(), sort)
    bool comp(const pair<int,int> &a, const pair<int,int> &b) {
        return (a.second - a.first < b.second - b.first);
    }

    lambda function:
    auto comp = [](int& a, int& b){ return freq[a] < freq[b] };

2. Class comparator overloading the operator (Only used for set, map, priority_queue, multimap and multiset)
    priority_queue<int, vector<int>, comp> pq;

    class comp {
        bool operator()(int a, int b) {
            
        } 
    } 

3. auto cmp = [](int a, int b) { return ... };
std::set<int, decltype(cmp)> s;
*/
