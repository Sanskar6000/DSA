/*
1. Comparator functions used with sort(a.begin(), a.end(), sort) -> for vector
    bool comp(const pair<int,int> &a, const pair<int,int> &b) {
        return (a.second - a.first < b.second - b.first);
    }

    lambda function:
    auto comp = [](const int& a, const int& b){ return freq[a] < freq[b] };

2. Class comparator overloading the operator (Only used for set, map, priority_queue, multimap and multiset)
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    if not using decltype use this (Avoid it as much as possible): 
    class comp {
        public:
        bool operator()(const int &a, const int &b) {
            
        } 
    } 

3. auto cmp = [](const int &a,const int &b) { return ... }; -> Here a and b are passed by value
std::set<int, decltype(cmp)> s;
*/  

string s;
getline(cin, s);
cout << s;
