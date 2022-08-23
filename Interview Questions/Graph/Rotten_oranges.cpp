//We will use Breadth First Search
//Taking rotten oranges in a queue
//Applying BFS
//For checking if all oranges are rotten
//We will keep count of all total oranges and oranges processed in a queue
//If both are not equal some oranges are left for decaying
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int total = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] != 0) total++;
            //Push Rotten oranges
            if(grid[i][j] == 2) q.push({i, j});
        }
    }
        
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
        
    int current = 0, ans = 0;
    //Perform BFS
    while(!q.empty()) {
        int size = q.size();
        current += size;
        for(int i = 0; i < size; i++) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if(!q.empty()) ans++; 
    }
        
    if(current != total) return -1;
    return ans;
}