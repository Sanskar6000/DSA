//for(i = 1; i < N; i++) next_Value = curr_value - (totalSum - A[i - 1]) + A[i - 1] * (N - 1)
int max_sum(int A[],int N)
{   
   
    int curr = 0;
    for(int i = 0; i < N; i++) {
        curr += A[i] * i;
    }
    
    int curr_sum = 0;
    for(int i = 0; i < N; i++) {
        curr_sum += A[i];
    }
     int ans = curr;
    for(int i = 1; i < N; i++) {
        int next_value = curr - (curr_sum - A[i - 1]) + A[i - 1] * (N - 1);
        
        curr = next_value;
        ans = max(ans, next_value);
    }
    return ans;
}