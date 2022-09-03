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
    vector<int> d(n);
 
    for(int i = 0; i < n; i++) {
        int l, m;
        cin >> l >> m;
        a[i] = l;
        d[i] = m;
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
 
    int i = 0, j = 0;
    int curr = 0, ans = 0;
    while(i < n) {
        if(d[j] <= a[i]) {
            curr--;
            j++;
        }
        else {
            curr++;
            i++;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}