#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
        int goodSubarray(vector<int>& nums, int k){
            int result = 0;
            int left = 0;
            unordered_map<int, int> frequency;
            for(int right=0; right<nums.size(); right++){
                int num=nums[right];
                frequency[num]++;
                while(frequency[num]>k){
                    int numl=nums[left];
                    frequency[numl]--;
                    if(frequency[numl]==0){
                        frequency.erase(numl);
                    }
                    left++;

                }
                result = max(result,right-left+1);
            }
            return result;
        }
};
int main(){
  
    
    Solution sol;
    
    vector<int> nums={1,2,1,2,1,2,1,2};
    int k=1;
    int result=sol.goodSubarray(nums, k);
    cout<<result;
  
}