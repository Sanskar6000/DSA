//BFS goes level wise hence we can calculate distance

class BFS{
    queue<int> q;
    bool vis[N];
    int dis[N];

    vis[x] = true;
    dis[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int s = q.front();
        q.pop();

        for(auto u : adj[s]) {
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }
};