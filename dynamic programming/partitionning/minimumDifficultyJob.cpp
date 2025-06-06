#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> nums;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        this->nums=jobDifficulty;
        return dp(0, d);
    }
    int dp(int i, int k){
        if(i==nums.size()){
            if(k==0) return 0;
            return 1001;
        }
        if(k<=0) return 1001;
        int ans=1001;
        int mx=0;
        for(int j=i; j<nums.size(); j++){
            mx=max(mx, nums[j]);
            ans=min(ans, dp(j+1, k-1)+mx);
        }
        return ans;
    }
};
int main(){
    Solution solution;
    vector<int> nums= {6,5,4,3,2,1};
    vector<int> nums2= {1,1,1};
    cout<<solution.minDifficulty(nums,2);
}