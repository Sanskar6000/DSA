//Learnt multiset upperbound
#include<bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> st;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        st.insert(h);
    }

    for(int i = 0; i < m; i++) { 
        int t;
        cin >> t;
        auto it = st.upper_bound(t);
        //If it is at begining that means number equal to that number or smaller that that does not exists
        if(it == st.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            st.erase(it);
        }
    }
}