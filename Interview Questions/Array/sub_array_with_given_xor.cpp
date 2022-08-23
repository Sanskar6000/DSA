//Take a Map and keep adding all xors
//Check xor mathematically if present in map

int Solution::solve(vector<int> &A, int B) {
    int xorr = 0, count = 0;
    map<int, int> m;
    for(auto i : A) {
        xorr = xorr ^ i;
        if(xorr == B) count++;

        if(m.find(xorr ^ B) != m.end()) count += m[xorr ^ B];

        m[xorr]++;
    }    
    return count;
}