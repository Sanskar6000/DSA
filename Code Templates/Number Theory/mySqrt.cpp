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

//Function to find floor(sqrt)
int sqrt(int x){
    int l=1,r=1e9+5,ans=0,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (mid*mid<=x){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }return ans;
}