#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT32_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                ans=min(ans, nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans=min(ans, nums[low]);
                low=mid+1;
            }
            else{
               
                ans=min(ans, nums[mid]);
                high=high-1;               
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
    vector<int> nums={1,0,0,1,1,1,1};
    cout<<solution.findMin(nums);
}