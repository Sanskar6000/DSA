//For finding shortest distance from a 'Source' node to all other nodes in graph

//Using priority queue for greedy Approach, i.e., shortest distance for next node will pass shortest distance of prev node
/* 
Approach:
1. Use a minimum heap, storing {dis, node}
2. Use a distance array, mark everything as infinity initially
3. We will push in priority queue only when the current path is less than previously computed path
4. We are using min heap because we are making sure minimum distance has been computed before
*/

// Time Complexity: O(N + E)logN
// Space ComplexityL O(N)

const int INF = 1e9;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    //Min heap <dis, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
    //distance array
    vector<int> dis(V, INF);
    pq.push({0, S});
    //IMP
    dis[S] = 0;
    while(!pq.empty()){
        int distance = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        for(auto it : adj[vertex]) {
            int nextNode = it[0];
            int nextDis = it[1];
 
                    
            if(dis[nextNode] > dis[vertex] + nextDis) {
                dis[nextNode] = dis[vertex] + nextDis;
                pq.push({dis[nextNode], nextNode});
            }
        }
    }
        
    return dis;
}