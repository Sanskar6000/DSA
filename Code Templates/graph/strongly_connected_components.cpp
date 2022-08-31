/* In the mathematical theory of directed graphs, a graph is said to be strongly connected if every vertex is reachable from every other 
vertex. The strongly connected components of an arbitrary directed graph form a partition into subgraphs that are themselves strongly 
connected. It is possible to test the strong connectivity of a graph, or to find its strongly connected components, in linear time 
(that is, Θ(V + E)). */

//Kosaraju's Algorithm
/* Makes use of the fact that the transpose graph (the same graph with the direction of every edge reversed) has exactly the same strongly
connected components as the original graph. */

//Intuition: If we smartly do dfs in reverse order, we will find components
/* 
1. Sort all nodes in order of finishing time using Stack (Toposort)
2. Transpose the graph (Reverse all the edges)
3. DFS according to finishing TIME

TC = O(N + E) + O(N + E) 
SC = O(N + E) + O(N) + O(N) 
*/

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = 1;
    for(auto it : transpose[node]) {
        if(!vis[it]) {
            revDFS(it, vis, transpose);
        }
    }
}

int main() {
    stack<int> st;
    //Toposort
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    //Transpose -> Reverse of graph
    vector<int> transpose[n];
    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        for(auto it: adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            cout << "Strongly Connected Componenet: ";
            revDFS(node, vis, transpose);
            cout << endl;
        }
    }
}
