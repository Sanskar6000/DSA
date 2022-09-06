int countSmallerorEqualtoMid(vector<int> &A, int M) {
    int low = 0, high = A.size() - 1;
    while(low <= high) {
        int mid = (low + high)/2;

        if(A[mid] <= M) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MIN, high = INT_MAX, n = A.size(), m = A[0].size();
    while(low <= high) {
        int mid = (low + high)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += countSmallerorEqualtoMid(A[i], mid);
        }
        if(cnt <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
