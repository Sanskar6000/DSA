#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;

        auto it = s.upper_bound(t);
        if(it == s.end()) {
            s.insert(t);            
        }
        else {
            s.erase(it);
            s.insert(t);
        }
    } 

    cout << s.size();
}