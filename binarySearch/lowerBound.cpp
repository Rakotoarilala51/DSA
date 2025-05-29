#include<vector>
#include<iostream>
#include<algorithm>
#include<chrono>
using namespace std;
int lowerbound(vector<int>& nums, int x){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = (high+low)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> nums, int x){
    int high=nums.size()-1;
    int low=0;
    int ans=nums.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;

}
int main(){
    vector<int> nums={1,3,5,5,8,19};
    int x=6;
    int k = lower_bound(nums.begin(), nums.end(), x)-nums.begin();
    cout<<lowerbound(nums, x)<<endl;
    
}