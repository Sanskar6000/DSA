//2 ^ 31 - 1 = 	2,147,483,647
    
    int myAtoi(string s) {
        int i = 0, ans = 0, sign = 1;
        
        //Eliminating White spaces
        while(s[i] == ' ') i++;
        
        if(s[i] == '-' || s[i] == '+') {
            sign = 1 - 2 * (s[i] == '-');
        }
        
        i++;
        while(s[i] >= '0' && s[i] <= '9') {
            //Checking before storing the last digit 
            if((ans > INT_MAX/10) || (ans == INT_MAX/10 && s[i] > '7')) {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            
            //Storing ans
            ans = 10 * ans + (s[i] - '0');
            i++;
        }
        
        return ans * sign;
    }