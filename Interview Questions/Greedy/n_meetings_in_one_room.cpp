bool comp(Item i1,Item i2) {
    return ((double)i1.value/i1.weight) > ((double)i2.value/i2.weight);
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {   
        //Warning only use size_t data type
        size_t sz = sizeof(arr)/sizeof(arr[0]);
        sort(arr, arr + n, comp);
        
        double ans = 0.00;
        
        for(int i = 0; i < n; i++) {
            if(W >= arr[i].weight) {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else {
                ans += ((double)arr[i].value/arr[i].weight) * W;
                break;
            }
        }
            
        return ans;
    }
        
};