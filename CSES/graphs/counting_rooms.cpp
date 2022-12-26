#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

void dfs(vector<vector<char>> &a, int i, int j) {
    if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || a[i][j] == '#') {
        return;
    }
    a[i][j] = '#';
    dfs(a, i + 1, j);
    dfs(a, i - 1, j);
    dfs(a, i, j + 1);
    dfs(a, i, j - 1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.') {
                dfs(a, i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';

  
}