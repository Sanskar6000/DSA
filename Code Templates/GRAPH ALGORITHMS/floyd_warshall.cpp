//All sources shortest path (DP) O(n^3)
//Take k that is via(in our first loop)
void floyd_warshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                 if(i == j) g[i][j] = 0;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
