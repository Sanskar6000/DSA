//Used to find number and positions of pattern p in string s
/*
Given two strings - a pattern s and a text t, determine if the pattern appears in the text and if it does, 
enumerate all its occurrences in O(|s| + |t|) time.
*/
class Solution {
public:
    const int mod = 1e9 + 7;
    const int INF = 1e9;

    int strStr(string haystack, string needle) {
        int ans = INF;
        int hhash = 0, nhash = 0;
        int p = 1;
        int hlen = haystack.size();
        int nlen = needle.size();

        for(int i = 0; i < nlen; i++) {
            hhash = (hhash + ((1LL * (haystack[i] - 'a' + 1) * p) % mod)) % mod;
            p = (1LL * p * 31) % mod;
        }

        p = 1;

        for(int i = 0; i < nlen; i++) {
            nhash = (nhash + ((1LL * needle[i] - 'a' + 1) * p) % mod) % mod;
            p = (1LL * p * 31) % mod;
        }
        int init = 1;
        
        if(hhash == nhash) {
                ans = min(ans, 0);
            }

        for(int i = nlen; i < hlen; i++) {

            hhash = (hhash - (1LL * (haystack[i - nlen] - 'a' + 1) * init) % mod + mod) % mod;
            init = (1LL * init * 31) % mod;

            hhash = (hhash + (1LL * (haystack[i] - 'a' + 1) * p) % mod) % mod;
            p = (1LL * p * 31) % mod; 

            nhash = ((1LL * nhash * 31) % mod) % mod;

            if(hhash == nhash) {
                ans = min(ans, i - nlen + 1);
            } 
        }

        return (ans == INF) ? -1 : ans;
    }
};