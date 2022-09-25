#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l = 0, r = 1000000;
    while(l < r) {
        int mid = r - (r - l)/2;
        cout << mid  << endl;
        // After printing each query you need to use special function to flush the output stream, because it is possible that some part of your output is left in the buffer.
        cout << flush;

        string s;
        cin >> s;
        if(s == "<") {
            r = mid - 1;
        }
        else {
            l = mid;
        }
    }

    cout << "! " << l << endl;
    cout << flush;  
}