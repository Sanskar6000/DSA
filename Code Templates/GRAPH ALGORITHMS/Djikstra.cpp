//Single Source Shortest Path
//0/1 BFS
//BFS helps to find shortest distance fro source to node if all weights are equal
//!Do not process negative edges
void djikstra() {
    vector<int> dis(n + 1, LLONG_MAX);
    dis[1] = 0;
    priority_queue<pair<int ,int>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int node = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        //using visited array will result in less time complexity 
        // if(vis[x][y]) continue;
        // vis[x][y] = 1;
        if(dis[node] < distance) continue;


        for(auto it : adj[node]) {
            int curr_node = it.first, d = it.second;
            if(d + distance < dis[curr_node]) {
                dis[curr_node] = d + distance;
                pq.push({-dis[curr_node], curr_node});
            }
        }
    }
}

//0/1 BFS -> logic in queue distnaces will be atmost 1 higher
vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}