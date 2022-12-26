#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> ones(n);
    int total = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            int t;
            cin >> t;
            sum += t;
        }
        total += sum;
        ones[i] = sum;
    }

    if(total/m != (total + m - 1)/m) {
        cout << -1 << '\n';
    }
    for(int i = 0; i < n; i++) {
        if(ones[i] != total/m) {
            for(int)
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}