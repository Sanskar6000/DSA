int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

// SPF and prime factors
int N;
vector<int> spf(N + 1);
vector<int> adj[N + 1]; 
void sieve() {
    for(int i = 0; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++){
            for(int j=i*i; j<=N; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
        }
    }
    
    for(int i = 2; i <= N; i++) {
        int num = i;
        while(num > 1) {
            int x = spf[num];
            while(num % x == 0) {
                num /= x;
            }

            adj[i].push_back(x);      
        }
    }

}