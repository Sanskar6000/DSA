/* Bipartite Graph: In the mathematical field of graph theory, a bipartite graph (or bigraph) is a graph whose vertices can be divided 
into two disjoint and independent sets U and V, that is every edge connects a vertex in U to one in V. Vertex sets U and V are usually 
called the parts of the graph. Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles. */

/* A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph 
connects a node in set A and a node in set B. */

//Solution
/* The two sets U and V may be thought of as a coloring of the graph with two colors: if one colors all nodes in U blue, and all nodes in V 
green, each edge has endpoints of differing colors, as is required in the graph coloring problem. In contrast, such a coloring is 
impossible in the case of a non-bipartite graph, such as a triangle: after one node is colored blue and another green, the third vertex 
of the triangle is connected to vertices of both colors, preventing it from being assigned either color. */

bool dfs(int node, vector<int> adj[], vector<int> &color) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!dfs(it, adj, color)) {
                return false;
            }
        }
        else if(color[it] == color[node]) {
            return false;
        } 
    }
    return true;
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> adj[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            adj[i].push_back(graph[i][j]);    
        }
    }
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!dfs(i, adj, color)) return false;
        }
    }      
    return true;
}