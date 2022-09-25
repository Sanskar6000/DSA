/* 
Same as Djikstra 
but Djikstra does not work with negative edges 
(if there is negative cycle then shortest path cannot be found)
With the help of Bellman Ford algorithm, we can detect a negative weight cycle

Algorithm: 
Relax all nodes n -  1 times
Relaxation:  d[u] + wt < dist[v]

Time Complexity: O(N) * O(E) = O(N * E)
Time Complexity for djikstra -> O(N + E)*logN

!!V.V. IMP -> We are doing n - 1 relaxations because it is based on concept that shortest path will have atmost n - 1 edges
Example: https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

vector<int> dist(N, inf);

dist[source] = 0;

for(int i = 1; i <= n - 1; i++) {
    for(auto it : edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            dist[it.v] = dist[it.u] + it.wt;
        }
    }
}

//!For checking negative weight cycle: If after n - 1 iteration and on nth iteration, there is decrease in distance