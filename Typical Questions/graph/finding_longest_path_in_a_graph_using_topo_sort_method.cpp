vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //Finding Longest Path in a Graph using TopoSort method
        //Eliminating all leaf nodes one by one
        
        if(n == 0) return {};
        if(n == 1) return {0};
        
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //Create indegree array
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        //Pushing leaf nodes in a queue
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            /*********************/
            ans.clear(); //When 1 or 2 nodes are remaining they will automatically be pushed in ans
            /********************/
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                //Imgine when 2 nodes are remaining in queue
                ans.push_back(node);
                //deleting curr and Making neighbours leaf nodes
                for(auto it : adj[node]) {
                    indegree[it]--;    
                    if(indegree[it] == 1) q.push(it);
                }
            }
        }
        
    
        return ans;
    }