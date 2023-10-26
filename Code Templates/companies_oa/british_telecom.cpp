#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

void Permutation(int i, vector<int>& nums, vector<vector<int>>& result) {
    if (i == nums.size() - 1) {
        result.push_back(nums);
    } else {
        for (int j = i, l = nums.size(); j < l; j++) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            Permutation(i + 1, nums, result);
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
}

int maxFriendshipPower(int N, int M, vector<vector<int>>& roads, vector<int>& A) {
    int result = 0;
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         cout << roads[i][j] << endl;
    //     }
    // }

    vector<int> B(A.size());
    int count = 1;
    for (int i = 0; i < A.size(); i++) {
        B[i] = count++;
    }

    // for (int i = 0; i < A.size(); i++) {
    //     cout << B[i] << endl;
    // }

    vector<vector<int>> result1;
    Permutation(0, B, result1);

    for (int i = 0; i < result1.size(); i++) {
        // int temp = 0;
        for (int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
            // result = (result + result1[i][j]) % mod;
        }
        // result = max(result, temp);
        cout << endl;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t_i = 0; t_i < T; t_i++) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> roads(M, vector<int>(2));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> roads[i][j];
            }
        }

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int out_ = maxFriendshipPower(N, M, roads, A);
        cout << out_ << endl;
    }

    return 0;
}
