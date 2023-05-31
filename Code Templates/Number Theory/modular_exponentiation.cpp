A^B % M
int modulo_exp(int a, int b, int m) {
    if(b == 0) return 1;
    int c = modulo_exp(a, b/2, m);
    if(b % 2 == 0) return (c * c) % m;
    return (c * c % m) * a % m;
}