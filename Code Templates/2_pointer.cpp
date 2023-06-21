int l = 0, cnt = 0;
for(int r = 0; r < n; r++) {
    if(s[r] != 'A' + i) cnt++;
    
    while(cnt > k) {
        if(s[l] != 'A' + i) cnt--;
        l++;
    }
    ans = max(ans, r - l + 1);
}