#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dp(int i, vector<int>& nums){
        if(i>=nums.size() || nums[i]==0 ) return false;
        if(i==nums.size()-1) return true;
        
        bool ans= false;
        for(int j=1; j<=nums[i]; j++){
            ans|=dp(j+i, nums);
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        return dp(0, nums);
    }
};
int main(){
    Solution solution;
    vector<int> nums={2,0};
    cout<<solution.canJump(nums);
}