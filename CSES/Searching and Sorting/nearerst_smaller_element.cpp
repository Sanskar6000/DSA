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
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if(s.empty()) {
            cout << "0 ";
        }
        else {
            cout << s.top() + 1 << " ";
        }
        s.push(i);
    }
}