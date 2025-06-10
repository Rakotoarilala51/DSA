#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int>& nums, int target){
    int low=0, high=nums.size()-1;
    while (low<=high)
    {
        int mid=(high+low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>=nums[low]){
            if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>=nums[mid] && target<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
    
}

int main(){
    vector<int> nums={7,8,9,1,2,3,4,5,6};
    cout<<bs(nums, 6);

}