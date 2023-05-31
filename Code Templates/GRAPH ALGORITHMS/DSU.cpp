// DSU Can ve used for detecting cycle in undirected graph
//TC -> O(alpha(n)) = amorterized time complexity(Almost Constant), alpha(n) -> reverse ackerman function
struct DSU {
    vector<int> parent, size;
 
    DSU () {}
 
    DSU(int n) {
        for(int i = 0; i < n; i++) parent.push_back(i);
        size.assign(n, 1);
    }
    
    int find(int v) {
        if(parent[v] == v) return v;

        return parent[v] = find(parent[v]);
    }
 
    void union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
};