for(int i = 0; i < V; i++) {
    if(!vis[i]) {
        queue q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()) {
            node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
}