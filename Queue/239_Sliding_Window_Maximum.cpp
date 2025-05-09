#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class MyQueue{
    public:
        deque<int> que;
        void pop(int value){
            if(!que.empty() && que.front() == value){
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        int get_front(){
            return que.front();
        }
};
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            if(k == 1)
                return nums;
            MyQueue que;
            vector<int> ans;
            for(int i = 0; i < k; i++){
                que.push(nums[i]);
            }
            ans.push_back(que.get_front());
            for(int i = 1; i < nums.size() - k + 1; i++){
                que.push(nums[i + k - 1]);
                que.pop(nums[i - 1]);
                ans.push_back(que.get_front());
            }
            return ans;
            
        }
    };

int main(){
    vector<int> n = {1,3,-1,-3,5,3,6,7};
    vector<int> a;
    Solution ans;
    a = ans.maxSlidingWindow(n, 3);
    for(auto it:a){
        cout<<"="<<it<<endl;
    }
    return 0;
}
