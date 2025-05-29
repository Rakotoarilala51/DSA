#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp(int i, vector<int> arr, int k){
        if(i==arr.size()) return 0;
        int ans=0, mx=0;
        for(int j=i; j<min((int)arr.size(), i+k); j++){
            mx=max(mx, arr[j]);
            ans=max(ans, (mx*(j-i+1))+dp(j+1, arr,k));
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        return dp(0, arr, k);
    }
};
int main(){
    Solution solution;
    vector<int> arr={1,15,7,9,2,5,10};
    cout<<solution.maxSumAfterPartitioning(arr,3);
}