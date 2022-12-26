#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

//!!IMP
//n + n/2 + n/3 + n/4 + ............. + n/n = log(n)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> hs(1e6 + 1, 0); 
    vector<int> a(n);
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        hs[temp]++;
    } 

    for(int i = 1e6; i >= 1; i--) {
        int count = 0;
        //logN
        for(int j = i; j <= 1e6; j += i) {
            count += hs[j];
        }
        if(count >= 2) {
            cout << i;
            return 0;
        }
    }
    cout << 1;
}