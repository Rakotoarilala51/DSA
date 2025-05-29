#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution{
    public:
        int countCompleteSubarrays(vector<int>& nums){
            int k=0;
            unordered_set<int> set;
            for(int i=0; i<nums.size(); i++){
                set.insert(nums[i]);
            }
            k=set.size();
            return atMost(k, nums)-atMost(k-1, nums);

        }
        int atMost(int k, vector<int>& nums){
            unordered_map<int, int> frequency;
            int count=0;
            int left=0;
            for(int right=0; right<nums.size(); right++){
                frequency[nums[right]]++;
                while(frequency.size()>k){
                    frequency[nums[left]]--;
                    if(frequency[nums[left]]==0){
                        frequency.erase(nums[left]);
                    }
                    left++;
                }
                count+=(right-left+1);
            }
            return count;
        }
};
int main(){
    Solution solution;
    vector<int> nums={5,5,5,5};
    cout<<solution.countCompleteSubarrays(nums);
}