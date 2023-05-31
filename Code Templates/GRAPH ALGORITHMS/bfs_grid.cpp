#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

int n, m;
vector<vector<char>> a; 
vector<vector<int>> vis; 
vector<vector<pair<int, int>>> path; 

int sx, sy, ex, ey;
//                                'U'      'D'     'L'     'R'
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> ch = {'D', 'U', 'R', 'L'};

bool isvalid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;

    if(vis[x][y]) return false;

    return true;
}

void solve() {
    cin >> n >> m;

    a.resize(n, vector<char>(m));
    vis.resize(n, vector<int>(m, 0));
    path.resize(n, vector<pair<int, int>>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') vis[i][j] = 1;
            if(a[i][j] == 'A') sx = i, sy = j;
            if(a[i][j] == 'B') ex = i, ey = j;
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    int ans = 
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        vis[x][y] = 1;

        for(auto it : moves) {
            int dx = it.first;
            int dy = it.second;
            if(isvalid(x + dx, y + dy)) {
                q.push({x + dx, y + dy});
                //Imp to mark vis to avoid tle
                vis[x + dx][y + dy] = 1;
                path[x + dx][y + dy] = {dx, dy};
            }
        }

    }
    if(path[ex][ey].first == 0 && path[ex][ey].second == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<char> ans;
    // dbg(make_pair(ex, ey));
    //  dbg(make_pair(sx, sy));
    while(ex != sx || ey != sy) {
        for(int i = 0; i < 4; i++) {
            bool flag = false;
            if(moves[i].first == -path[ex][ey].first && moves[i].second == -path[ex][ey].second) {
                ans.push_back(ch[i]);
                // dbg(path[ex][ey].first);
                // dbg(path[ex][ey].second);
                ex += moves[i].first;
                ey += moves[i].second;
   
                flag = true;
            }
            if(flag) break;
        }
        // dbg(make_pair(ex, ey));
       

    }
    
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto c : ans) cout << c;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}


