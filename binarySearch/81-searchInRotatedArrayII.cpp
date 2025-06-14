#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low++;
                high--;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    
                }
            }
        }
    }
};