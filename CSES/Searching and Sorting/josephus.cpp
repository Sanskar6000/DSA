#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int f(int n, int k) {
    if(n == 1) return 0;

    return (f(n - 1, k) + k)%n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;
    //Winner will be
    //f(n, k) = (f(n - 1, k) + k) % n;
    //if n == 1 return 1
    cout << f(n, 2) + 1;
}