// Array: [6 4 2 14 8 10 12 16]
//Approach -> Make array of pairs of numbers and their indices 
//Sort them
//Find Cycle size
//Add Cycle Size - 1 to answer

Time Complexity: O(N*log(N))
Space Complexity: O(N)

int minSwaps(vector<int>&nums)
	{   
	    int n = nums.size();
	    vector<pair<int, int>> p(n);
	    for(int i = 0; i < n; i++) {
	        p[i] = {nums[i], i};
	    }
	    
	    sort(p.begin(), p.end());
	    int ans = 0;
	    
	    //Make a visited Array
	    vector<int> vis(n, 0);
	    for(int i = 0; i < n; i++) {
	        if(p[i].second == i || vis[i]) continue;
	        
	        int cycle_size = 0;
	        int j = i;
	        while(!vis[j]) {
	            vis[j] = 1;
	            
	            j = p[j].second;
	            cycle_size++;
	        }
	        if(cycle_size > 0) ans += cycle_size - 1;
	    }
	    
	    return ans;
	}