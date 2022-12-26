#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    } 

    sort(a.begin(), a.end());
        // for(auto p : a) cout << p.first << " " << p.second << "\n";
    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
                int l = j + 1, r = n - 1;
                while(l < r) {
                    int sum = a[i].first + a[j].first + a[l].first + a[r].first;
                    // cout << sum << "\n";
                    if(sum == x) {
                        // cout << a[i].first << " " << a[l].first << " " << a[r].first << "\n";
                        cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second;
                        return 0;
                    }
                    else if(sum < x) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
        }
    }
    cout << "IMPOSSIBLE";
}