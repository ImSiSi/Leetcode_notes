#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i] && dp[j - coins[i]] != -1) {
                    if (dp[j] != -1)
                        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                    else
                        dp[j] = dp[j - coins[i]] + 1;
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sol;
    int result = sol.coinChange(coins, amount);
    if (result != -1)
        cout << "Minimum number of coins: " << result << endl;
    else
        cout << "Cannot make up the amount with given coins." << endl;
    return 0;
}