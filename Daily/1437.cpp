#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIndex=0;
        while(!nums[lastIndex]) lastIndex++;
        cout<<lastIndex<<endl;
        for(int i=lastIndex+1; i<nums.size(); i++){
            if(nums[i]){
                int distance=i-lastIndex-1;
                cout<<i<<" "<<distance<<endl;
                if(distance<k) return false;
                lastIndex=i;
            }
        }
        return true;
        
    }
};
int main(){
    Solution solution;
    vector<int> nums= {1,0,0,0,1,0,0,1};
    int k=2;
    cout<<solution.kLengthApart(nums,k);
}