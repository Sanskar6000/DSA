//Single Source Shortest Path
//!Works for negative edges
//The longest possible path in any single source shortest path is n - 1 edges when we perform n - 1
//relaxations we ensure that we have covered all the edges and shortest path is considered for our source and node

//In case of no negative cycles, there won't be a need to revisit a node
//When there is negative weight cycle distance will be -INF
//If we perform n - 1 propogations along all E edges, propogation is complete. We have Single Source Shortest Paths
//Exceptions Exists

//Belman ford only works for directed graphs if it undirected graph convert it to directed graph be keeping edges from both sides

//Algo
//Relax all edges 'n - 1' times
//if there are no negative cycles, our answer is the final answer in v * e steps
//When there are negative cycles, we can resolve sssp(s) in 2 * v * e steps

/*
no wts: BFS
positive wts: djikstra
negative weights and negative cycle: bellman ford 
*/

const int INF = 1e17;
const int NINF = INF * (-1);

struct triplet{
    int first;
    int second;
    int third;
};

int n, m;
vector<triplet> edges;
vector<int> dis;

//first part
void bellman_ford() {
    for(int i = 1; i < n; i++) {
        for(auto e : edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if(dis[u] == INF) continue;
            //Relaxation
            dis[v] = min(dis[v], dis[u] + d);
            //floor -> (-1 * 10**17) vs (-1 * 10**17 - 100)
            dis[v] = max(dis[v], NINF);
        }
    }

    //deal with negative weight cycles
    for(int i = 1; i < n; i++) {
        for(auto e : edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if(dis[u] == INF) continue;
            dis[v] = max(dis[v], NINF);
            //Relaxations after 'n - 1' cycles -> negative cycles
            if(dis[u] + d < dis[v]) {
                dis[v] = NINF;
            }
        }           
    }
}

