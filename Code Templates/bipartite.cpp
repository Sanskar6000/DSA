//Two color problem -> Coloring vertices of graph with only two colors
vector<int> vis, ans;

bool bfs(int node, vector<int> adj[], int color, int par) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        
    }
}

bool color_all(vector<int> adj[]) {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(!bfs(i, adj, 1, -1)) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n, m;int n, m;
vector<int> vis, ans;

bool dfs(int node, vector<int> adj[], int color, int par) {
    vis[node] = 1;
    ans[node] = color;
    for(auto it : adj[node]) {
      
            if(it == par) continue;
            if(ans[it] == 0) {
                if(!dfs(it, adj, ans[node] ^ 3, node)) return false;
            }
            if(ans[node] == ans[it]) return false;
            
     
        
    }

    return true;
}

bool color_all(vector<int> adj[]) {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(!dfs(i, adj, 1, -1)) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
 
    cin >> n >> m;
    vis.resize(n + 1);
    ans.resize(n + 1);
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(color_all(adj)) {
        for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    }
    else cout << "IMPOSSIBLE";

}
