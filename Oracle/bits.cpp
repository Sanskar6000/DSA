#include<bits/stdc++.h>
using namespace std;

int max_bit(int a) {
    int ans = 0;
    for(int i = 0; i <= 31; i++) {
        if(a & (1 << i)) ans = i;
    }

    return ans;
}

int main()
{   
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> bits(32, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int ind = max_bit(a[i]);

            ans += bits[ind];

            bits[ind]++;
        }

        cout << ans << '\n';
    }

}