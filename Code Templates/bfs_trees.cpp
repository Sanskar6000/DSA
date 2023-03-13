queue<pair<int, int>> q;
q.push({1, 0});

while(!q.empty()) {
    int node = q.front().first;
    int par = q.front().second;
    q.pop();
    cout << node << ' ';
    for(auto it : adj[node]) {
        if(it == par) continue;
        q.push({it, node});
    }
}

//graphs
queue<int> q;

q.push(1);
while(!q.empty()) {
    int node = q.front();
    vis[node] = 1;
    q.pop();
    for(auto it : ad[node]) {
        if(!vis[it]) {
            q.push(it);
            vis[it] = 1;a
        }
    }
}