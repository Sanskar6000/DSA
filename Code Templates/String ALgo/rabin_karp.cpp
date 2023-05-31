//Used to find number and positions of pattern p in string s
/*
Given two strings - a pattern s and a text t, determine if the pattern appears in the text and if it does, 
enumerate all its occurrences in O(|s| + |t|) time.
*/
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 7;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int blackbox(string &s) {
    int n = s.size(), hash = 0, p = 1;
    for(int i = 0; i < n; i++) {
        hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
        p = (p * 31 * 1LL) % mod;
    }

    return hash;
}

void rabinkarp() {
    string s, p;
    cin >> s >> p;

    int slen = s.size();
    int plen = p.size();

    int phash = blackbox(p);
    string temp = s.substr(0, plen);
    int shash = blackbox(temp);
    int cnt = 0;
    vector<pair<int, int>> pos;

    if(phash == shash) {
        cnt++;
        pos.push_back({0, pos - 1});
    }

    int prL = 1;
    int prR = power(31, plen);

    for(int i = plen; i < slen; i++) {
        shash = (shash - ((s[i - plen] - 'a' + 1)*prL)% mod + mod) % mod;
        shash = (shash + ((s[i] - 'a' + 1)*prR)%mod)%mod;
        phash = (phash*31)%mod;
        if(shash == phash) {
            cnt++;
            pos.push_back({i - plen + 1, i});
        }
        prL = (prL * 31) % mod;
        prR = (prR * 31) % mod;
    }

    cout << cnt << '\n';
    for(auto &[x,y] : pos) cout << x + 1 << ' ' << y + 1 << '\n';
}