#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> countingArray(101, 0);
        vector<int> sub(101,0);
        vector<int> result(nums.size(),0 );
        for(int i=0; i<nums.size();i++){
            countingArray[nums[i]]++;
            sub[nums[i]]++;
        }
        for(int i=1; i<countingArray.size(); i++){
            sub[i] +=sub[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            result[i]=sub[nums[i]]-countingArray[nums[i]];
        }
        return result;
    }
};
int main(){
    vector<int> result;
    Solution solution;
    vector<int> nums = {6,5,4,4,8};
    result = solution.smallerNumbersThanCurrent(nums);
    for(int num:result){
        cout<<num<<" ";
    }
}