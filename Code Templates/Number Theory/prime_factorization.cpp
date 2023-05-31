#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

void solve() {
    int x;
    cin >> x;
    if(x == 1) cout << 1 << "\n";
    else {  
        map<int, int> m;
        for(int i = 2; i * i <= x; i++) {
            while(x % i == 0) {
                m[i]++;
                x = x/i;
            }
        }
        if(x > 1) m[x]++;
        int ans = 1;
        for(auto p : m) {
            ans  *= (p.second + 1);
        }
         cout << ans << "\n";
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