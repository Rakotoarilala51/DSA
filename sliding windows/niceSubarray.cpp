#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        vector<int> arr;
        int countNiceSubarray(vector<int>& nums, int k){
            this->arr = nums;
            return atMost(k)-atMost(k-1);
        }
        int atMost(int k){
            int count=0, left=0;
            for(int right=0; right<arr.size(); right++){
                if(arr[right]&1) k--;
                while(k<0 && left<=right){
                    if(arr[left]&1)
                    k++;
                    ++left;
                }
                count+=right-left+1;
            }
            return count;
        }
};
int main(){
    Solution solution;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k=2;
    cout<<solution.countNiceSubarray(nums, k);
}