#include<bits/stdc++.h>
#define int long long
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int>dp(amount+1, 0);
        for(int i=1; i<=amount; i++){
            dp[i]=INT_MAX;
            for(int c: coins){
                if(i-c>=0 && dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
int32_t main(){
    Solution solution;
    vector<int> coins = {1,2,5};
    cout<<solution.coinChange(coins, 11);
}