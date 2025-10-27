#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT32_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=nums.size()-3; i++){
            int left = i+1, right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                
            }
        }
    }
};