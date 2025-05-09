#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void tracking(vector<int>& candidates, int target, int start) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            tracking(candidates, target - candidates[i], i);
            path.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tracking(candidates, target, 0);
        return result;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    
    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : res) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}