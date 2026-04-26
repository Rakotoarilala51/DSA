#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> result;
        vector<int> maximumLeft(nums.size(), 0), maximumRight(nums.size(), 0);
        maximumLeft[0]=nums[0];
        maximumRight.back() = nums.back();
        result.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            maximumLeft[i] = max(nums[i-1], maximumLeft[i-1]);
        }
        for(int i=nums.size()-2;  i>=0; i--){
            maximumRight[i] = max(nums[i+1], maximumRight[i+1]);
        }
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i]>maximumLeft[i] || nums[i]>maximumRight[i])result.push_back(nums[i]);
        }
        if(nums.size()!=1){
            result.push_back(nums.back());
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,2,4,2,3,2};
    Solution solution;
    solution.findValidElements(nums);
    return 0;
}