//Calculate x^n
//take ans as 1
//Take power as n
//divide power by 2 and base by itself
//when power will be odd
//multiply ans by base and decrease power by 1
//Loop will end when power remains 1 and eventually 0
double myPow(double x, int n) {
    double ans = 1;
    long nn = n;
    if(n < 0) nn = nn * -1;
    while (nn > 0) {
        if(nn % 2 == 0) {
            x = x * x;
            nn = nn/2;
        }
        else {
            ans = ans * x;
            nn--;
        }
    }
    if(n < 0) ans = (1/ans);
    return ans;
}