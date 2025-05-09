#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int result = robImp(nums, 0, nums.size() - 1); // 不偷最後一間
        int result1 = robImp(nums, 1, nums.size());    // 不偷第一間
        return max(result, result1);
    }

    int robImp(vector<int>& nums, int start, int end) {
        vector<int> dp(2, 0);
        int max_val = 0;
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = start + 2; i <= end; i++) {
            max_val = std::max(dp[1], dp[0] + nums[i - 1]);
            dp[0] = dp[1];
            dp[1] = max_val;
        }
        return max_val;
    }
};

int main() {
    vector<int> houses = {2, 3, 2}; // 範例輸入：不能偷第一和最後同時偷
    Solution sol;
    int maxRob = sol.rob(houses);
    cout << "Maximum amount that can be robbed: " << maxRob << endl;
    return 0;
}