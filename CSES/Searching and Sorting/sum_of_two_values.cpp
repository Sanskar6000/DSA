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
        int t;
        cin >> t;
        a[i] = {t, i + 1};
    } 
    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    while(i < j) {
        int sum = a[i].first + a[j].first;
        if(sum == x) {
            cout << a[i].second << " " << a[j].second;
            break;
        }
        else if(sum < x) {
            i++;
        }
        else {
            j--;
        }
    }
    if(i == j) cout << "IMPOSSIBLE";
}