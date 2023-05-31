//(a,b) -> Top Left corner & (c,d) -> Bottom Right corner
int pf[n][n];

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        cin >> a[i][j];
        pf[i][j] = a[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1]; 
    }
}

int q;
cin >> q;
while(q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];
}