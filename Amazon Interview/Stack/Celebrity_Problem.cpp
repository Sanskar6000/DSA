//Brute: Calculate Indegree and outdegree of everyone;
//If indegree = n - 1 & outdegree = 0 ---> This Person will be celebrity

//Using Stack
// If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
// If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
// Repeat above two steps till there is only one person.
// Ensure the remained person is a celebrity. (What is the need of this step?)

// Algo:
bool knows(int i, int j, vector<vector<int> >& M) {
        return M[i][j];
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        //Push every person to stack
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        //Popping until last celebrity is left
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            //If a knows b, a can't be celebrity
            if(knows(a, b, M)) {
                s.push(b);
            }
            //a doesn't know b, b can't be celebrity
            else {
                s.push(a);
            }
        }
        
        // now checking reamining elemnt is Celebrity or Not
        int c = s.top();
        s.pop();
        
        for(int i = 0; i < n; i++) {
            if((i != c) && (knows(c, i, M) || !(knows(i, c, M)))) {
                return -1;
            }
        }
        return c;
    }