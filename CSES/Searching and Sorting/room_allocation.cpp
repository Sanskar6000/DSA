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
    vector<pair<pair<int, int>, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    //Train that will depart first will be popped
    priority_queue<pair<int, int>> pq;
    vector<int> k(n, 0);
    int ans = 0, room = 0;
    
    for(int i = 0; i < n; i++) {
        if(pq.empty()) {
            room++;
            pq.push({-a[i].first.second, room});
            k[a[i].second] = room;
        }
        else {
            pair<int, int> min = pq.top();
            //Train is departed
            if(-min.first < a[i].first.first) {
                pq.pop();
                pq.push({-a[i].first.second, min.second});
                k[a[i].second] = min.second;
            }
            else {
                room++;
                pq.push({-a[i].first.second, room});
                k[a[i].second] = room;
            }
        }
        //Minimum Pahije
        ans = max(ans, (int)pq.size());
    }

    cout << ans << "\n";
    for(int i = 0; i < n; i++) {
        cout << k[i] << " ";
    }
}