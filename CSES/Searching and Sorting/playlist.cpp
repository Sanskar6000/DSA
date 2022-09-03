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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, curr = 0;
    map<int, int> m;
    int i = 0, j = 0;
    while(j < n) {
        //If not found
        if(m.find(a[j]) == m.end() || m[a[j]] == 0) {
            m[a[j]]++;
            curr++;
            j++;            
        }
        else {
            m[a[i]]--;
            i++;
            curr--;
        }
        ans = max(ans, curr);
    }

    cout << ans;
}