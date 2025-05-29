#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
        int minimumIndex(vector<int>& nums){
            int n=nums.size();
            unordered_map<int, int> freq;
            unordered_map<int, int> freq2;
            for( int x : nums){
                freq[x]++;
            }
           for(int i=0; i<n; i++){
            freq[nums[i]]--;
            freq2[nums[i]]++;
            if(freq2[nums[i]]*2>i+1 && (freq[nums[i]])*2>n-i-1) return i;
           }
     
            return -1;
        }
};
int main(){
    vector<int> nums={1,2,2,2};
    Solution solution;
    cout<<solution.minimumIndex(nums);
}