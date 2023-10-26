//LogN per query
void make_set(int v) {
    parent[v] = v;
}

//Time Complexity = O(logN)
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

//Union
//Time Complexity -> Alpha(N) < 4
//1. Union by size
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(sz[a] < sz[b])
            swap(a, b);
        //assuming b is small
        parent[b] = a;
        //small is added in larger one
        sz[a] += sz[b];
    }
}

//2.Union by Rank
void make_set(int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}