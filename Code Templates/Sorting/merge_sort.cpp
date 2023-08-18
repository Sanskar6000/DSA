//Finding indices i,j such that a[i] >= a[j]
//problem: https://codeforces.com/contest/1676/problem/H2
#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cout << (#x) << ':' << ' ' << (x) << endl
#define ll long long

ll merge(vector<ll> &a, int l, int mid, int r) {
    int i = l, j = mid, k = 0;
    ll cnt = 0;
    vector<ll> temp(r - l + 1);

    while((i < mid) && (j <= r)) {
        if(a[i] < a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        }
        else {
            // dbg(i);
            // dbg(j);

            temp[k] = a[j];
            cnt += (mid - i);
            k++;
            j++;
        }
    }

    while(i < mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    while(j <= r) {
        temp[k] = a[j];
        k++;
        j++;
    }

    //upadating array a
    for(i = l, k = 0; i <= r; i++, k++) {
        a[i] = temp[k];
    }
    // dbg(l);
    // dbg(mid);
    // dbg(r);
    // dbg(cnt);
    // cout << '\n';
    return cnt;
}

ll mergeSort(vector<ll> &a, int l, int r) {
    ll cnt = 0;

    if(l < r) {
        ll mid = (l + r)/2;
        cnt += mergeSort(a, l, mid);
        cnt += mergeSort(a, mid + 1, r);

        //merging
        cnt += merge(a, l, mid + 1, r);
    }

    return cnt;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &i : a) cin >> i;

    cout << mergeSort(a, 0, n - 1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}