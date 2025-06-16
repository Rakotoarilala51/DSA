#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int count=0;
        unordered_map<int,int> left;
        left[nums[0]]++;
        unordered_map<int, int> right;
        for(int i=1; i<nums.size(); i++){
            right[nums[i]]++;
        }
        for(int i=1; i<nums.size()-1; i++){
              right[nums[i]]--;
              int target = nums[i] * 2;
    if (left.count(target) && right.count(target)) {
        count = (count + 1LL * left[target] * right[target]) % MOD;
    }
            left[nums[i]]++;
            if(right[nums[i]]==0){
                right.erase(nums[i]);
            }
        }
        return count;
    }
};
int main(){
    Solution sol;
    vector<int> nums={0,1,0,0};
    cout<<sol.specialTriplets(nums);
}