#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target) {
        int mid, front = 0, rear = nums.size() - 1;
        if(target == nums[front])
            return front;
        if(target == nums[rear])
            return rear;
        while(front <= rear){
            mid = front + (rear - front) / 2;
            if(target < nums[mid]){
                rear = mid - 1;
            }
            else if(target > nums[mid]){
                front = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }    
};


int main(){
    int a[] = {1,2,3,4};
    vector<int> ar(a, a + sizeof(a)/ sizeof(int));
    Solution ans;

    cout<<"ans="<<ans.search(ar,2);
    return 0;
}