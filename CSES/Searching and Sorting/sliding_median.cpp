#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = k/2 - (!k % 2);

    if(!k % 2) {
        for(int i = 0 + s; i < n - s - 1; i++) {
            cout << min(a[i], a[i + 1]) << " ";
        }
    }
    else {
        for(int i = 0 + s; i < n - s; i++) {
            cout << a[i] << " ";
        }
    }
}