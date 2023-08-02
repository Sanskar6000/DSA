/*
Given a weighted, undirected graph G with n vertices and m edges. 
You want to find a spanning tree of this graph which connects all vertices and has the least weight 
(i.e. the sum of weights of edges is minimal). A spanning tree is a set of edges such that any vertex can 
reach any other by exactly one simple path. The spanning tree with the least weight is called a minimum spanning tree.
*/

//Prim's Algorithm -> O(m * logn)
const int INF = 1e9;

void prims() {
    vector<int> vis(n + 1, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    
    int sum = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(vis[node]) continue;

        vis[node] = true;

        sum += distance;
        for(auto it : adj[node]) {
            int curr_node = it.first, d = it.second;
            //major difference between Djikstra and prims
            if(!vis[curr_node]) pq.push({-d, curr_node});
        }
    }
}

//Kruskal's Algorithm -> O(M * logN)
//Sort edges according to wt merge them
vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, w;
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;

parent.resize(n);
rank.resize(n);

for (int i = 0; i < n; i++) 
    make_set(i);

auto comp = [](Edge &a, Edge &b) {
    return a.w < b.w;
}

sort(edges.begin(), edges.end(), comp);

for (Edge e : edges) {
    if(find_set(e.u) != find_set(e.v)) {
        cost += e.w;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}