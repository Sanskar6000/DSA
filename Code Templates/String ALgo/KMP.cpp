// Text ->       a b x a b c a b c a b y
// Pattern ->    a b c a b y
// LPS Array ->  0 0 0 1 2 0

//Same use as Rabin_Karp
vector<int> longestsuffixprefix(string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while(i < n) {
        if(s[i] == s[len]) {
            lps[i] = len + 1;
            len++; i++;
        }
        else {
            if(len == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

void kmp() {
    string s, p;
    cin >> s >> p;

    int plen = p.size();
    int slen = s.size();

    vector<int> pattern_lps = longestprefixsuffix(p);
    int len = 0;
    int i = 0;
    int cnt = 0;
    while(i < slen) {
        if(s[i] == p[len]) {
            i++;
            len++;
        }
        else {
            if(len != 0) {
                len = pattern_lps[len - 1];
            }
            else {
                i++;
            }
        }
    }
    if(len == plen) {
        cnt++;
        len = pattern_lps[len - 1];
    }
    cout << cnt << '\n';
}

A : [ -533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, 
-609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 
667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 
141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35 ]