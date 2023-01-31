//
ll random_number(ll a, ll b) {
    return a + (rand() % b);
}

struct Interactor{
    int hiddenNumber;
    int limitQueries = 0;
    int queries = 0;
    Interactor(){
        hiddenNumber = random_number(1, 1000);
        limitQueries = 15;
    }
    char query(int x, bool printOutput){
        if(printOutput){
            cout << "? " << x << endl;
        }
        assert(queries < limitQueries); // your code stops here
        // if this is false give out a runtime error)
        queries++;
        char ans = '=';
        if(x > hiddenNumber){
            ans = '>';
            
        }else if(x < hiddenNumber){
            ans = '<';
        }else{
            ans = '=';
        }
        if(printOutput){
            cout << ans << endl;
        }
        return ans;
    }
    bool correctOutput(int x){
        if(x == hiddenNumber){
            cout << "Passed for " << x << endl;
        }else{
            cout << "Failed" << endl;
            cout << "Hidden Number: " << hiddenNumber << endl;
            cout << "Output Given: " << x << endl;
        } 
        return x == hiddenNumber;
    }
};
void solve(){  
    for(int tries = 0; tries <= 1e5; tries++){
        Interactor codeforces = Interactor();
        int l = 1, r = 1000;
        while(true){
            int mid = (l + r) / 2;
            char codeforcesOutput;
            // cin >> codeforcesOutput;
            codeforcesOutput = codeforces.query(mid, false);
            if(codeforcesOutput == '='){
                assert(codeforces.correctOutput(mid));
                break;
            }else if(codeforcesOutput == '>'){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }
} 


/*******************************************Second Code****************************************************/
#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cout << (#x) << ':' << ' ' << (x) << endl
#define ll long long

ll random_number(ll a, ll b) {
    return a + (rand() % b);
}

struct Interactor{
        int n;
        vector<int> a;
        int limitQueries = 0, queries;
        Interactor(int N){
            n = N;
            a.resize(n);
            for(int i = 0; i < n; i++) {
                a[i] = random_number(1, 100);
            }

            cout << "Hidden Array: ";
            for(auto i : a) cout << i << ' ';
            cout << endl;
        }

        int query(int l, int r) {
            assert(l >= 1 && r <= n && l < r);
            int sum = 0;
            for(int i = l; i <= r; i++) {
                sum += a[i - 1];
            }

            return sum;
        }

        bool correctOutput(vector<int> output) {
            assert(output.size() == n && output == a);
            return true;
        }
};

void solve() {
    int n;
    Interactor codeforces = Interactor(5);
    // cin >> n;
    n = codeforces.n;
  
    vector<int> ans(n, 0);
    vector<int> a;
    for(int i = 1; i <= n - 1; i++) {
        cout << "? " << i << ' ' << n << ' ' << endl;
        int x;
        // cin >> x;
        x = codeforces.query(i, n);
        a.push_back(x);
    }

    cout << "? " << 1 << ' ' << n - 1 << endl;
    int x;
    // cin >> x;
    x = codeforces.query(1, n - 1);
    a.push_back(x);

    for(int i = 0; i < ans.size() - 2; i++) {
        ans[i] = a[i] - a[i + 1];
    }
    ans[n - 1] = a[0] - a[n - 1];

    int sum = 0;
    for(auto i : ans) sum += i;
    ans[n - 2] = a[0] - sum;

    cout << "! ";
    for(auto i : ans) cout << i << ' ';
    cout << endl;
    codeforces.correctOutput(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}