#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    long long countFairPairs(vector<int>& nums, int lower, int upper){
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        for(int i=0; i<nums.size(); i++){
            if(upper-nums[i]<nums[i]){
                break;
            } 
            int left=i+1;
            int right=nums.size()-1;
            while(left<nums.size() && ((nums[left]+nums[i])<lower)){
                left++;
            }
            while((nums[right]+nums[i])>upper) right--;
            count+=(right-left+1);

        }
        return count;
    }
};

int main(){
    vector<int> nums={-1,0};
    Solution solution;
    cout<<solution.countFairPairs(nums, 1,1);
}