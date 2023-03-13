

class BinaryExponentiation {
    typedef long long ll;
    const int mod = 1e9 + 1;

    public:
    //If a, b, mod <= 1e9
int myPow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b % 2) {
            ans = (ans * a) % mod;
            b--;
        }
        else {
            a = (a * a) % mod;
            b = b/2;
        }
    }
    return ans;
}

    //If a <= 10^18
    //a^b % mod = ((a % mod)^ b) % mod    
    ll myPow(ll a, ll b) {
        a %= mod;
        //Or a = a = 2 ^ 1024
        a = myPow(2, 1024);
        ll ans = 1;
        while(b) {
            if(b % 2) {
                ans = (ans * a) % mod;
                b--;
            }
            else {
                a = (a * a) % mod;
                b = b/2;
            }
        }
        return ans;
    }

    //If a <= 10 ^ 18, M <= 10 ^ 18, b <= 10 ^ 9
    //To avoid overflow of 1e18 and 1e18
    //Adding a to then taking modulo ----> a times
};


