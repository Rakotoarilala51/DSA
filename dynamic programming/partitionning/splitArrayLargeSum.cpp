#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int dp(int i, vector<int>& nums, int m){
            
            if(i==nums.size()){
                if(m==0) return 0;
                return 1e9;
            }
            if(m<=0) return 1e9;
            int ans=1e9, sum=0;
            for(int j=i; j<nums.size(); j++){
                sum+=nums[j];
                ans=min(max(sum, dp(j+1, nums, m-1)), ans);
            }
            return ans;
        }
        int splitArray(vector<int>& nums, int m){
            return dp(0, nums, m);
        }
};
int main(){
    Solution solution;
    vector<int> nums={7,2,5,10,8};
    cout<<solution.splitArray(nums,2);
}