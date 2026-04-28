#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        nth_element(nums.begin(), nums.begin()+(n-k), nums.end());
        return nums[n-k];
    }
};
int main(){
    Solution solution;
    vector<int> nums = {3,2,1,5,6,4};
    cout<<solution.findKthLargest(nums, 3);
}