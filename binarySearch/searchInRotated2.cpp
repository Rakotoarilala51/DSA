#include<iostream>
#include<vector>
using namespace std;
bool searchInRotatedArray2(vector<int>& nums, int target){
    int low=0, high=nums.size()-1;
    while (low<=high)
    {
        int mid=(high+low)/2;
        if(nums[mid]==target) return true;
        if(nums[low]==nums[mid] && nums[high]==nums[mid]){
            low++;
            high--;
            continue;
        }
        else if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(target<=nums[high] && target>=nums[mid]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return false;
}
int main(){
    vector<int> nums={3,3,9,1,2,3,3};
    cout<<searchInRotatedArray2(nums, 3);

}