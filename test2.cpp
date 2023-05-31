#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

void solve() {
    int n;
    cin >> n;

    int a = 2 * n, b = 2;
    for(int i = 0; i < n/2; i++) {
        cout << a << ' ' << b << ' ';
        a -= 2; b += 2;  
    } 

    if(n % 2) cout << a - 2 << '\n';
    else cout << '\n';

    a = 1; b -= 1;
    for(int i = 0; i < n/2; i++) {
        cout << a << ' ' << b << ' ';
        a += 2; b += 2;  
    } 

    if(n % 2) cout << a + 2 << '\n';
    else cout << '\n';

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