  void dfs(int source, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
        vis[source] = 1;
        ans.push_back(source);
        for(auto node : adj[source]) {
            if(!vis[node]) {
                dfs(node, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> ans;
        dfs(0, adj, vis, ans);
        return ans;
    }