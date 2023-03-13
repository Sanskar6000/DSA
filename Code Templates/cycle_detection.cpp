//For UnDirected Graph
int n, m, start, e;
vector<int> vis, parent;

bool dfs(int node, int par, vector<int> adj[]) {
    vis[node] = 1;
    parent[node] = par;
    for(auto it : adj[node]) {
        if(it == par) continue;
        if(vis[it]) {
            start = it, e = node;
            return true;
        }
        else if(dfs(it, node, adj)) return true;
    }

    return false;
}

bool isCycle(vector<int> adj[]) {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, adj)) {
                return true;
            }
        }
    }

    return false;
}

//For Directed Graph
