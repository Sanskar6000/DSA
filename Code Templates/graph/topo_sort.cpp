//Topological sort is used for DAG(Directed Acyclic Graph) ONLY
//Tutorial: https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/

bool isTopo(int n, vector<int> adj[]) {
        //Computing indegrees
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto node : adj[i]) {
                indegree[node]+++;
            }
        }
        
        vector<int> toposort;
        
        //Indegree is Zero push in queue
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        //Apply BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return toposort;
    }