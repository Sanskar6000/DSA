//for integers
while(r - l >= 3) {
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;

    val1 = f(m1);
    val2 = f(m2);

    if(val1 > val2) {
        r = m2;
    }
    else {
        l = m1;
    }
}

ans = max(f(l), f(l + 1), f(l + 2));

//for real numbers
while(r - l >= error) {
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;

    val1 = f(m1);
    val2 = f(m2);

    if(val1 > val2) {
        r = m2;
    }
    else {
        l = m1;
    }
}

//Ternary Search Pattern of convex functions
class Solution {
private:
    long long f(long long mid, vector<int> &nums, vector<int> &cost) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - mid) * cost[i];
        }

        return ans;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // 5 5 4 4 3 3 4 5 6 6
        long long l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end()), ans;
        while(l <= r) {
            long long mid = l + (r - l)/2;
            long long y1 = f(mid, nums, cost), y2 = f(mid + 1, nums, cost);
            ans = min(y1, y2);
            if(y1 > y2) {
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return ans;
    }
};
