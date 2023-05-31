// Cycle Detection and retrieveal for undirected graph
int n;
vector<int> adj[];
vector<bool> vis;
vector<int> parent;
int start_cycle, end_cycle;

bool dfs(int node, int par) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(it == par) continue;
        if(vis[it]) {
            start_cycle = it;
            end_cycle = node;
            return true;
        }
        parent[it] = node;
        if(dfs(it, node)) return true;
    }

    return false;
}

void find_cycle() {
    vis.assign(n, false);
    parent.assign(n, -1);
    start_cycle = -1;

    for(int i = 0; i < n; i++) {
        if(!vis[i] && dfs(i, parent[i]))
        break;
    }

    if(start_cycle == -1) cout << "NO CYCLE\n";
    else {
        vector<int> cycle;
        cycle.push_back(start_cycle);

        for(int i = end_cycle; i != start_cycle; i = parent[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(start_cycle);

        cout << "CYCLE FOUND\n";
        for(auto i : cycle) cout << i << " ";
    }
}

//Cycle Detection and retrieval for directed graph
int n;
vector<int> adj[];
vector<int> col;
vector<int> parent;
int start_cycle, end_cycle;

bool dfs(int node) {
    color[node] = 1;

    for(auto it : adj[node]) {
        if(color[it] == 0) {
            parent[it] = node;
            if(dfs(it)) return true;
        }
        else if(color[it] == 1) {
            start_cycle = it;
            end_cycle = node;
            return true;
        }
    }
    color[node] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    start_cycle = -1;

    for(int i = 0; i < n; i++) {
        if(color[i] == 0 && dfs(i)) break;
    }

    if(start_cycle == -1) cout << "NO CYCLE\n";
    else {
        vector<int> cycle;
        cycle.push_back(start_cycle);

        for(int i = end_cycle_cycle; i != start_cycle; i = parent[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(start_cycle);

        cout << "CYCLE FOUND\n";
        for(auto i : cycle) cout << i << " ";
    }
}