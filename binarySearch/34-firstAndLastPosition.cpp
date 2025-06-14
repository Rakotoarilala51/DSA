#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int starting=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        if(starting==nums.size()||nums[starting]!=target) return {-1,-1};
        int ending=upper_bound(nums.begin(), nums.end(), target)-nums.begin();

        return {starting, ending-1};
    }
};
int main(){
    Solution solution;
    vector<int> nums={5,7,7,8,8,10};
    vector<int>result=solution.searchRange(nums,8);
    for(int num:result){
        cout<<num<<" ";
    }
}