#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(const vector<int>& nums, vector<bool>& picked) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !picked[i - 1]) {
                continue; 
            }
            if (!picked[i]) {
                path.push_back(nums[i]);
                picked[i] = true;
                backtracking(nums, picked);
                picked[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> picked(nums.size(), false);
        sort(nums.begin(), nums.end()); 
        backtracking(nums, picked);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution sol;
    vector<vector<int>> permutations = sol.permuteUnique(nums);

    cout << "Unique permutations are:" << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}