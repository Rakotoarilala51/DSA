#include<iostream>
#include<vector>
using namespace std;
int numberOfTimes(vector<int>& nums){
    int low=0;
    int high=nums.size()-1;
    int mini=INT32_MAX;
    int index=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
            if(mini>nums[low]){
                index=low;
                mini=nums[low];
            }
            break;
        }
        if(nums[low]<=nums[mid]){
            if(mini>nums[low]){
                index=low;
                mini=nums[low];
            }
            low=mid+1;
        }
        else{
            if(mini>nums[mid]){
                index=mid;
                mini=nums[mid];
            }
            high=mid-1;
        }
    }
    return index;
}
int main(){
    vector<int> nums={7,8,9,10,1,2,3,4,5,6};
    cout<<numberOfTimes(nums);
}