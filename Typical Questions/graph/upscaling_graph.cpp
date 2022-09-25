
void dfs(vector<vector<int>> &a, int i, int j) {
    if(i < 0 || j < 0 || i >= a.size() || j >= a.size() || a[i][j] == 1) return;
        
    a[i][j] = 1;
        
    dfs(a, i + 1, j);
    dfs(a, i - 1, j);
    dfs(a, i, j + 1);
    dfs(a, i, j - 1);
}
    
int regionsBySlashes(vector<string>& grid) {
        // 3*3 upscaling
    int n = grid.size();
    vector<vector<int>> a(n * 3, vector<int> (n * 3, 0));
        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '/') {
                a[i * 3][j * 3 + 2] = a[i * 3 + 1][j * 3 + 1] = a[i * 3 + 2][j * 3] = 1; 
            }
            // ******
            else if(grid[i][j] == '\\') {
                a[i * 3][j * 3] = a[i * 3 + 1][j * 3 + 1] = a[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
        
        //perform dfs
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(a[i][j] == 0) {
                cout << "dfs" << endl;
                ans++;
                dfs(a,i ,j);
            }
        }
    }
        
        
        
    return ans;
}

