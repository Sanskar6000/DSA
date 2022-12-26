#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

// int myPow(int a, int b) {
//     int ans = 1;
//     while(b) {
//         if(b & 1) {
//             ans *= a;
//             b--;
//         }
//         else {
//             a *= a;
//             b /= 2;
//         }
//     }
//     return ans;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i * i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            ans = (ans + i) % mod;
        }
    }

    cout << ans;
}