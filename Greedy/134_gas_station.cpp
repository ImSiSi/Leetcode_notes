#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int cur = 0;
            int start = 0;
            for(int i = start; i < gas.size(); i++){
                cur += gas[start] - cost[start];
                start = (start + 1) % gas.size();
                while(cur > 0 && start != i){
                    cur += gas[start] - cost[start];
                    start = (start + 1) % gas.size();
                }
                if(start == i && cur >= 0){
                    return i;
                }
            }
            return -1;
        }
    };

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};  
    vector<int> cost = {3, 4, 5, 1, 2};  

    int start = sol.canCompleteCircuit(gas, cost);
    cout << "The starting gas station is: " << start << endl;  

    return 0;
}