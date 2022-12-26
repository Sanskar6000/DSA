class DFS {   
void dfs(int s) {
    if(vis[s]) return;
    vis[s] = true;
    for(auto u : adj[s]) {
        dfs(u);
    }
}
};
