#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1, ans=INT32_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[high]==nums[mid] && nums[low]==nums[mid]){
                ans=min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<nums[high]){
                ans=min(ans, nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans=min(ans, nums[low]);
                low=mid+1;
            }else{
               
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
    vector<int> nums={3,1,3};
    cout<<solution.findMin(nums);
}