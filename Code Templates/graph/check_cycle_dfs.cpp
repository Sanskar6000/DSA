   bool isCycle(int node, int parent, vector<int> vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i]) {
                if(isCycle(i, node, vis, adj)) return true;
            }
            //If it is visited and node == parent return false
            else if(i != parent) return true;
        }
        
        return false;
    }
    
    bool dfs(vector<int> adj[], int numCourses) {
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                //Passing Node and Parent
                if(isCycle(i, -1, vis, adj)) return true;
            }
        }
        
        return false;
    }