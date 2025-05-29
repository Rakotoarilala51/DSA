#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int subarrayWithSum(vector<int>& nums, int goal){
        return atmostk(nums, goal) - atmostk(nums, goal-1);
    }
    int atmostk(vector<int>& nums, int k){
        int left = 0, sum = 0, result = 0;

        for(int right = 0; right<nums.size(); right ++){
            sum += nums[right];

            while(sum>k && left<=right){
                sum -=nums[left];
                left++;
            }
            result += right - left +1;
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {0,0,0,0,0};
    int goal=0;
    cout<<sol.subarrayWithSum(nums, goal);
}
