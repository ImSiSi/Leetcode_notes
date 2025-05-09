#include<cstdlib>
#include<vector>
#include<iostream>
#include <algorithm>
using std::vector;
using std::max;

// LeetCode 56: Merge Intervals
// Strategy: Sort first, and then compare if next interval's left is in the current interval
// merge these two intervals with (left, max(cur->right, next->right)) and continue loop
// Time complexity : O(nlogn)  Space complexity : O(n) 
class Solution {
    public:
        static bool cmp(vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        }
        vector<vector<int>> merge(vector<vector<int>>& inter) {
            if(inter.size() <= 1)
                return inter;
            sort(inter.begin(), inter.end(), cmp);
            vector<vector<int>> result;
            int left = inter[0][0], right = inter[0][1];
            for(int i = 1; i < inter.size(); i++){
                if(inter[i][0] <= right){
                    right = max(inter[i][1], right);
                }
                else{
                    result.push_back({left, right});
                    left = inter[i][0];
                    right = inter[i][1];
                }
            }
            //push the last interval to result
            result.push_back({left, right});
            return result;
        }
    };