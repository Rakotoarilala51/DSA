#include<iostream>
#include<vector>
using namespace std;
int minimum(vector<int>& nums){
    int low=0, high=nums.size()-1;
    int mini=INT32_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        //verifier le sorted part
        if(nums[low]<=nums[high]){
            mini=min(mini, nums[low]);
            break;
        }
        if(nums[low]<=nums[mid]){
            mini=min(mini, nums[low]);
            low=mid+1;
        }
        else{
            mini=min(mini, nums[mid]);
            high=mid-1;
        }
    }
    return mini;
}
int main(){
    vector<int> nums={7,8,9,1,2,3,4,5,6};
    cout<<minimum(nums);
}