#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
    
}

void solve() {
    vector<int> nums = {1,6,7,8}, moveFrom = {1,7,2}, moveTo = {2,9,5};
    vector<int> ans = relocateMarbles(nums, moveFrom, moveTo);

    for(auto i : ans) cout << i << ' ';
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