//We will implement standard binary seacrh
//Middle element will be matrxi[mid/cols][mid % cols]
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
        
    int rows = matrix.size(), cols = matrix[0].size();
        
    int l = 0, r = rows*cols - 1;
    while(r >= l) {
        int mid = (l + r)/2;
        int m = matrix[mid/cols][mid % cols];
        if(target == m) {
            return true;
        }
        else if (m > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return false;
}