#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nextNonDuplecate=2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[nextNonDuplecate-2]){
            nums[nextNonDuplecate]=nums[i];
               if(i!=nextNonDuplecate){
                    nums[i]=INT32_MAX;
               }
               nextNonDuplecate++;
            }
        }
        return nextNonDuplecate;
    }
};
int main(){
    Solution solution;
    vector<int> nums = {1};
    int result = solution.removeDuplicates(nums);
    for(int num: nums){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<result<<endl;
}