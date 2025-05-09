#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int result = 0;
            int down = 0;
            int cur = 1;
            int max = 0;
            for(int i = 0; i < ratings.size() - 1; i++){
                result += cur;
                // cur = the candies of i+1
                // max = the most candies before going down
                if(ratings[i] < ratings[i + 1]){
                    cur ++;
                    max = cur;
                    down = 0;
                }
                else if(ratings[i] > ratings[i + 1]){
                    down ++;
                    if(max <= down){
                        result ++;
                        max ++;
                    }
                    if(down > 1){
                        result += down - 1;
                    }
                    cur = 1;
                }
                else{
                    cur = 1;
                    max = cur;
                    down = 0;
                }
            }
            result += cur;
            return result;
        }
    };
    
    int main(){
        Solution ans;
        vector<int> dif = {1,2,3,4,3,4,5,4,2,3};
        cout<<ans.candy(dif);
        return 0;
    }

