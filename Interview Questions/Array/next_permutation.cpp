//First make k-- as we will be considering 0 based indexing
//our first element will be k/(n - 1)! from the list and from that list will be k % (n - 1)!

string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;
    for(int i = 1; i < n; i++) {
        numbers.push_back(i);
        fact *= i;
    }

    //numbers = {1, 2, 3, 4}

    numbers.push_back(n);
    string ans = "";
        
    //Reduce k by 1 initially
    k = k - 1;
        
    while(true) {
        //Pick first element
        ans = ans + to_string(numbers[k / fact]);
            
        //removing the element (takes O(1) time)
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size() == 0) {
            break;
        }
            
        //next permutation from subset number
        k = k % fact;
            
        //Value of factorial
        fact = fact / numbers.size();
        }

    return ans;
} 