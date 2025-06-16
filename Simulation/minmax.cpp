#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size()>>1;
        
        while(nums.size()>1){
            vector<int> newNums(nums.size()>>1, 0);
            for(int i=0; i<=newNums.size(); i++){
                if(!i&1){
                    cout<<nums[2*i+1]<<endl;
                    newNums[i]=min(nums[i*2], nums[i*2+1]);
                }else{
                    newNums[i]=max(nums[i*2], nums[i*2+1]);
                }
               
            }
            nums=newNums;
        }
        return nums[0];
    }
};
int main(){
    Solution solution;
    vector<int> nums={1,3,5,2,4,8,2,2};
    cout<<solution.minMaxGame(nums);
}