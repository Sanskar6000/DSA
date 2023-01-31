int mySqrt(int x) {
    int l = 0, r = x;
    int ans = -1;
    while(l <= r) {
        int mid = r - (r - l)/2;
        if((long long) mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ((long long) ans * ans == x) ? ans : -1;
}
