#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    if(k > m) {
        cout << "NO\n";
        return;
    }

    int remain = n - floor(n/k) * k;
    int num = 0;
    
    for(int i = 0; i < m; i++) {
        if(a[i] > (n/k)) {
            if(remain > 0) {
                if((a[i] - (n/k)) > 1) {
                    cout << "NO\n";
                    return;
                }
                else {
                    num++;
                }
            }
            else {
                cout << "NO\n";
                return;
            }
            
        }
    }
    if(num > remain) {
        cout << "NO\n";
        return;
    } 
    cout << "YES\n";
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