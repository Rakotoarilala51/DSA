#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n,0);
        vector<int> even(n,0);
        vector<int> result(n,0);
        odd[n-1]=nums[n-1]&1?0:1;
        even[n-1]=nums[n-1]&1?1:0;
        for(int i=n-2; i>=0; i--){
            cout<<((nums[i]&1))<<endl;
            odd[i]=odd[i+1]+(!(nums[i]&1));
            even[i]=even[i+1]+(nums[i]&1);
        }
        for(int i=0; i<n; i++){
            cout<<odd[i]<<",";
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<<even[i]<<",";
        }
        for(int i=0; i<n-1; i++){
            if(n%2==1) result[i]=odd[i];
            else result[i]=even[i];
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<<result[i]<<",";
        }
        return result;
    }
};
int main(){
    Solution solution;
    vector<int>nums={5,1};
    solution.countOppositeParity(nums);
}