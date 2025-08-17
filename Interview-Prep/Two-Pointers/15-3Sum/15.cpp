#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> nums;
    vector<vector<int>> threeSum(vector<int>& nums) {
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i==0 || (i>0 && this->nums[i]!=this->nums[i-1])){
                twoSum(-this->nums[i], i+1, nums.size()-1);
            }
        }
        return result;
    }
    void twoSum(int target, int left, int right){
        while(left<right){
            int sum = this->nums[left]+this->nums[right];
            if(sum==target){
                vector<int> triplets;
                triplets.push_back({-target, });
                triplets.push_back(this->nums[left]);
                triplets.push_back(this->nums[right]);
                result.push_back(triplets);
                right--;
                left++;
                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
                //return;
            }
            else if(sum>target){
                right--;
            }else{
                left++;
            }
        }
    }
};
int main(){
    vector<vector<int>> result;
    vector<int> nums{2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution solution;
    result = solution.threeSum(nums);
    for(auto vec: result){
        for(int num: vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}