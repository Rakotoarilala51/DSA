#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> memo;
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        memo.resize(n+1,-1);
        return dp(n);
    }
    int dp(int n){
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        int ans = INT_MIN;
        for(int j=1; j<=n; j++){
            ans=max(ans, j*dp(n-j));
        }
        return memo[n]=ans;
    }
};
int main(){
    Solution solution;
    vector<int> dp(31,0);
    for(int i=0; i<=30; i++){
        dp[i]=solution.integerBreak(i);
    }
    for(int i=1; i<=30; i++){
        cout<<i<<" "<<dp[i]<<endl;
    }
    
    
}