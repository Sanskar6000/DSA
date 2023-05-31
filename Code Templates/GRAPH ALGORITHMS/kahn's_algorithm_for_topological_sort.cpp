#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        indegree[b - 1]++;
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < n; i++) {
       if(indegree[i] == 0) q.push_back(i); 
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for(auto it : adj[curr]) {
            indegree[it]--;

            if(indegree[it] == 0) q.push(it);
        }
    }

    if(ans.size() != n) cout << "IMPOSSIBLE\n";
    else for(auto i : ans) cout << i + 1 << ' ';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}