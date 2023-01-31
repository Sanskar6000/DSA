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
