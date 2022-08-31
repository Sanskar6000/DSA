  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto child : adj[node]) {
                if(!vis[child]) {
                    q.push(child);
                    vis[child] = 1;
                } 
            }
        }
        
        return ans;
    }