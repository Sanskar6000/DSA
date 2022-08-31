bool isTopo(int n, vector<int> adj[]) {
        //Computing indegrees
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto node : adj[i]) {
                indegree[node]++;
            }
        }
        
        int counter = 0;
        
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
            counter++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return (counter == n);
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //We want our graph to be directed and acyclic(DAG) hence using Topological Sort (BFS) Indegree Method
        
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
     
        
        return isTopo(numCourses, adj);
    }