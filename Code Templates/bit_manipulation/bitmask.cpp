#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

void add(int &subset, int x) {
    subset = (subset ^ (1 << (x - 1)));
}

void remove(int &subset, int x) {
    subset = (subset ^ (1 << (x - 1)));
}

void display(int subset) {
    //set contains numbers {1 ,...., 10}
    for(int bit_no = 0; bit_no <= 9; bit_no++) {
        if(subset & (1 << bit_no)) {
            cout << bit_no + 1 << ' ';
        }
    }
    cout << '\n';
}

void solve() {
    int subset = 15;
    display(subset);   
    remove(subset, 2);
    display(subset);
    add(subset, 5);
    display(subset); 
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