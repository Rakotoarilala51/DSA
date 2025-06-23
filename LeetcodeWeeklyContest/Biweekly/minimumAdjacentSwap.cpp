#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int j, count=0, n=nums.size()-1;
        for(int i=0;i<nums.size()-1; i++){

            if(nums[i]%2==nums[i+1]%2){
               
                j=i+1;
                while(nums[j]%2==nums[i]%2 && j<n){
                    j++;
                }
                 //cout<<i<<":"<<nums[j]<<endl;
                
                if(j==n && nums[n]%2==nums[i]%2) return -1;
                while(j>i+1){
                    swap(nums[j], nums[j-1]);
                    j--;
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums={4,5,6,8};
    Solution solution;
    cout<<solution.minSwaps(nums)<<endl;
    for(int num: nums) cout<<num<<" ";
}