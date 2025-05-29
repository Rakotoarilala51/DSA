#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int functionName(vector<int>& nums, int k){
            int maxi=0, left=0, sum=0, numberOfMaxi=0, n=nums.size();
            for(int i=0; i<n; i++){
                maxi=max(maxi, nums[i]);
            }
            for(int right=0; right<n; right++){
                if(nums[right]==maxi) numberOfMaxi++;
                while(numberOfMaxi>=k){
                    sum+=n-right;
                    if(nums[left]==maxi){
                        numberOfMaxi--;
                    }
                    left++;
                }
            }
            return sum;           
        }
};
int main(){
    Solution solution;
    vector<int> nums={1,3,2,3,3};
    cout<<solution.functionName(nums, 2);
}