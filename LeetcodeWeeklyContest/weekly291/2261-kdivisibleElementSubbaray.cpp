#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int atMostK(vector<int>& nums, int k, int p){
        int left=0;
        int result=0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]%p==0) k--;
            while(k<=0){
                if(nums[left]%p==0) k++;
                left++;
            }
            result=right-left+1;
        }
        return result;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        return atMostK(nums, k, p)-atMostK(nums, k-1,p);
    }
};
int main(){
    vector<int> nums={2,3,3,2,2};
    Solution solution;
    cout<<solution.countDistinct(nums, 2,2);
}