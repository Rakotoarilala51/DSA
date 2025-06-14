#include<iostream>
#include<vector>
using namespace std;
int minimum(vector<int>& nums){
    int low=0, high=nums.size()-1;
    int mini=INT32_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        //verifier le sorted part
        if(nums[low]<nums[high]){
            mini=min(mini, nums[low]);
            //break;
        }
        if(nums[low]<=nums[mid]){
            mini=min(mini, nums[low]);
            low=mid+1;
        }
        else{
             high=mid-1;
            mini=min(mini, nums[mid]);
           
        }
    }
    return mini;
}
int main(){
    vector<int> nums={1,0,0,1,1,1,1};
    cout<<minimum(nums);
}