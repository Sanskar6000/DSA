const int mod = 1e9 + 7;

int blackbox(string &s) {
    int n = s.size(), hash = 0, p = 1;
    for(int i = 0; i < n; i++) {
        hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
        p = (p * 31 * 1LL) % mod;
    }

    return hash;
}

//How to reduce Probability of collision
//initial prob = 1/mod
//now prob = 1/mod1 * 1/mod2

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

void solve() {
    string a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    int n = a.size();
    set<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        int bad = 0, p1 = 1, p2 = 1, hash1 = 0, hash2 = 0;
        for(int j = i; j < n; j++) {
            int x = a[j] - 'a';
            bad += (b[x] == '0');
            if(bad > k) break;
            hash1 = (hash1 + (((x + 1)) * p1) % mod1) % mod1;
            hash2 = (hash2 + (((x + 1)) * p2) % mod2) % mod2;
            p1 = (p1 * 31) % mod1;
            p2 = (p2 * 37) % mod2;
            ans.insert({hash1, hash2});
        }

    }
    dbg(ans);
    cout << ans.size() << '\n';
}