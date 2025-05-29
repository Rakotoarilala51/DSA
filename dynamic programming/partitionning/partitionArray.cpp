#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int maxSumAfterPartitioning(vector<int>& nums, int k){
            return dp(0,nums, k);
        }
        int dp(int i,vector<int>& nums,int& k){
            if(i==nums.size()) return 0;
            int sum=0;
            int mx=0;
            for(int j=i; j<min(int(nums.size()), i+k); j++){
                mx=max(mx, nums[j]);
                sum=max(sum, mx*(j-i+1)+dp(j+1, nums, k));
            }
            return sum;
        }
};
int main(){
    Solution solution;
    vector<int> nums={1,15,7,9,2,5,10};
    cout<<solution.maxSumAfterPartitioning(nums, 3);
}