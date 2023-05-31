#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif

#define int long long int

set<string> st;
int dp[101];
const int INF = 1e7;

int solve(string s, int ind, int n) {
    if(ind == -1) return 0;

    if(dp[ind] != -1) return dp[ind];

    int res = INF;
    for(int i = 0; i <= ind; i++) {
        string t = s.substr(i, ind - i + 1);
        if(st.find(t) != st.end()) {
            res = min(res, solve(s, i - 1, n));
        } 
    }
   
    res = min(res, 1 + solve(s, ind - 1, n));
    //    dbg(ind, l, r);
    // dbg(ind, l, r);
    // dbg(ind, l);
    return dp[ind] = res;
}       
    
int minExtraChar(string s, vector<string>& dictionary) {
    memset(dp, -1, sizeof(dp));
    int n = s.size();

    for(int i = 0; i < dictionary.size(); i++) {
        st.insert(dictionary[i]);
    }    

    return solve(s, n - 1, n);
}       

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<string> dictionary;
    string t;
    while(cin >> t) {
        dictionary.push_back(t);
    }

    cout <<  minExtraChar(s, dictionary);  
    // for(auto i : dp) cout << i << ' ';
}