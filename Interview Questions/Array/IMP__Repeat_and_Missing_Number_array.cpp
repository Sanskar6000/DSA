// Problem: https://www.interviewbit.com/problems/repeat-and-missing-number-array/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
   int XOR = 0;
   for(int i = 0; i < A.size(); i++) {
       XOR ^= A[i];
       XOR ^= (i + 1);
   }
   int count = 0;
   int ansXor = XOR;
   while(XOR) {
       if(XOR & 1) {
           break;
       }
       count++;
       XOR = XOR >> 1;
   }

   int XOR1 = 0;
   int XOR2 = 0;
   for(int i = 0; i < A.size(); i++) {
       if(A[i] & (1 << count)) {
           XOR2 ^= A[i];
       }
       else {
           XOR1 ^= A[i];
       }
       if((i + 1) & (1 << count)) {
           XOR2 ^= (i + 1);
       }
       else {
           XOR1 ^= (i + 1);
       }
   }
   vector<int> ans;
   int a = ansXor^XOR2, b = ansXor^XOR1, aC = 0, bC = 0;
   for(int i = 0; i < A.size(); i++) {
       if(A[i] == a) aC++;
       if(A[i] == b) bC++;
   }
   if(aC == 2) {
       ans.push_back(a);
       ans.push_back(b);
   }
   else {
       ans.push_back(b);
       ans.push_back(a);
   }
   return ans;
}
