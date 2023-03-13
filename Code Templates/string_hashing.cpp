const int mod = 1e9 + 7;

int blackbox(string &s) {
    int n = s.size(), hash = 0, p = 1;
    for(int i = 0; i < n; i++) {
        hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
        p = (p * 31 * 1LL) % mod;
    }

    return hash;
}