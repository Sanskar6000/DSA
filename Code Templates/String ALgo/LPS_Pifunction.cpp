//Longest Prefix Suffix
//This Function returns Length of LPS at every index
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