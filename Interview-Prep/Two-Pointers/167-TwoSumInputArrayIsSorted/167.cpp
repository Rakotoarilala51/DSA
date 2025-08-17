#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> result;
        int left=0, right=nums.size()-1;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum == target){
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            else if(sum>target){
                right--;
            }
            else{
                left ++;
            }
        }
        return {};
    }
};
int main(){
    vector<int> nums={-2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    for(int num:result){
        cout<<num<<" ";
    }
}