 void dfs(string source, string destination, unordered_map<string, vector<pair<string, double>>> &m, 
            unordered_map<string, int> &vis, double &ans, double temp) {
        // if Source is already visited we will Return
        if(vis.count(source)) return;
        
        // if Source or Destination is not found we will return
        if(!(m.count(source) && m.count(destination))) return;
        
        if(source == destination) {
            ans = temp;
            return;
        }
        
        vis[source] = 1;
        
        for(auto s : m[source]) {
            dfs(s.first, destination, m, vis, ans, temp * s.second);
        }
        
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Create a Directed Weighted Graph can be created only using Map
        unordered_map<string, vector<pair<string, double>>> m;
        
        for(int i = 0; i < equations.size(); i++) {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        vector<double> sol;
        
        for(int i = 0; i < queries.size(); i++) {
            string source = queries[i][0];
            string destination = queries[i][1];
            
            // Create a Visited Array
            unordered_map<string, int> vis;
            
            double ans = -1.0, temp = 1.0;
            
            dfs(source, destination, m, vis, ans, temp);
            
            sol.push_back(ans);
        }
        
        return sol;
    }