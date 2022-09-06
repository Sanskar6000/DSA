     string reverseWords(string s) {
        reverse(0, s.size() - 1, s);
        
        reversewords(s.size(), s);
        
        eliminatespaces(s.size(), s); 
         
        return s;
    }
    void reverse(int start, int end, string &s) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
    
    void reversewords(int size, string &s) {
        int i = 0, j = 0;
        while(i < size) {
            //using two pointers i and j, i will be pointing at first letter of word and j at last letter of a word
            i = j;
            while(s[i] == ' ' && i < size) i++;
            j = i;
            while(s[j] != ' ' && j < size) j++;
            reverse(i, j - 1, s);
            
        }
    }
    
   void eliminatespaces(int size, string &s) {
       int i = 0, j = 0;
       while(j < size) {
           while(s[j] == ' ' && j < size) j++;
           while(s[j] != ' ' && j < size) swap(s[i++], s[j++]);
           while(s[j] == ' ' && j < size) j++;
           if(j < size) i++;
       }
       s = s.substr(0, i);
   }