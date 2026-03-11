#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0;
        int maximum=0;
        while(!nums[left] && left<nums.size()-1) left++;
        for(int right=left+1; right<nums.size(); right++){
            if(left==INT_MIN & nums[right]){ 
                left=right;
                cout<<left<<endl;
            }
            if(!nums[right]){
                left=INT_MIN;
            }
            maximum=max(maximum, right-left+1);
        }
        return maximum;
    }
};
int main(){
    vector<int> nums={1,1,0,1,1,1};
    Solution solution;
    cout<<solution.findMaxConsecutiveOnes(nums);
}