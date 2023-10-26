const int MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];
		
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) {
		inv[i - 1] = inv[i] * i % p;
	}
}
		
long long nCr(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

/*
Leetcode -> Count K-Subsequences of a String With Maximum Beauty
class Solution {
public:
    const int mod = 1e9 + 7;

    int exp(int a, int b) {
        int ans = 1;
        while(b) {
            if(b % 2) {
                ans = (1LL * ans * a) % mod;
                b--;
            }
            else {
                a = (1LL * a * a % mod) % mod;
                b = b/2;
            }
        }

        return ans;
    }

    int inv(int n) {
        return exp(n, mod - 2);
    }

    int fact(int n) {
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            ans = (1LL * ans * i % mod) % mod;
        }

        return ans;
    }

    int nCr(int n, int r) { 
        return (1LL * fact(n) % mod * inv(fact(n - r)) % mod * inv(fact(r)) % mod) % mod;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int hs[26] = {0};
        for(auto c : s) hs[c - 'a']++;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < 26; i++) {
            if(hs[i] > 0) pq.push(hs[i]);
            if(pq.size() > k) pq.pop();
        }

        if(pq.size() < k) return 0;

        int ans = 1;
        int ele = pq.top(), cnt1 = 0, cnt = 0;
        while(!pq.empty() && pq.top() == ele) {
            cnt1++;
            pq.pop();
        }
        for(int i = 0; i < 26; i++) {
            if(ele == hs[i]) cnt++;
        } 
        
        while(!pq.empty()) {
            cout << pq.top() << ' ' << 1 << '\n';
            ans = (1LL * ans * nCr(pq.top(), 1) % mod) % mod;
            pq.pop();
        }

        ans = (1LL * ans * nCr(cnt, cnt1) % mod) % mod;

        for(int i = 1; i <= cnt1; i++) {
            ans = (1LL * ans * nCr(ele, 1) % mod) % mod;
        }

        return ans;
    }
};
*/
