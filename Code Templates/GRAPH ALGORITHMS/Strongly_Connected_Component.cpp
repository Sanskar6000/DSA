//!!For Directed Graphs only
//Every pair of vertex is reachable from one another 
//!https://usaco.guide/CPH.pdf#page=167

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }    
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT) {
    vis[node] = 1;
    for(auto it : adjT[node]) {
        if(!vis[it]) {
            dfs2(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj) {
    vector<int> vis(V);
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<vector<int>> adjT(V);

    for(int i = 0; i < V; i++) {
        vis[i] = 0;
        for(auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    int scc = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }

    return scc;
}