int parent[n], rank[n];
for(int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
}
//Code for finding Parent
int findPar(int node) {
    if(node == parent[node]) return node;

    //Path Compression
    parent[node] = findPar(parent[node]); 
}

void Union(int i, int j) {
    int u = findPar(i);
    int v = findPar(j);

    //One having rank higher will be parent
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[u] = v;
        rank[v]++;
    }
}