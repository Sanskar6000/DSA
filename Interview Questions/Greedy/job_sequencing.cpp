//Sort the array accoring to profit
//Perform the job on given day(deadline)
//If not available perform on previous day
// TC = O(NlogN) + O(N * M)

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}

bool comp(Job a, Job b) {
    //Sorting in decreasing order
    return (a.profit > b.profit);
}

//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr + n, comp);
        
    //Create Array of deadlines
    int deadlines = -1; 
    for(int i = 0; i < n; i++) {
        deadlines = max(deadlines, arr[i].dead);
    }
        
    vector<int> slot(deadlines + 1, -1);
    int maxProfit = 0, jobs = 0;
        
    for(int i = 0; i < n; i++) {
        //Traversing Deadline array
        for(int j = arr[i].dead; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                jobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }
    return {jobs, maxProfit};
} 