//We will check for first row or first column to be zero
//Then iterate from i = 1 & j = 1 in reverse order
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
	bool col0 = false, row0 = false;
	
	for(int i = 0; i < cols; i++) {
		if(matrix[0][i] == 0) row0 = true;
	}
	for(int i = 0; i < rows; i++) {
		if(matrix[i][0] == 0) col0 = true;
	}
	
	for(int i = 1; i < rows; i++) {
		for(int j = 1; j < cols; j++) {
			if(matrix[i][j] == 0){
			matrix[i][0] = 0;
			matrix[0][j] = 0;
		}
	}
}
	for(int i = 1; i < rows; i++) {
		for(int j = 1; j < cols; j++) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if(row0) {
		for(int j = 0; j < cols; j++) matrix[0][j] = 0;
	}
	if(col0) {
		for(int i = 0; i < rows; i++) matrix[i][0] = 0;
	}
    }