#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int memo[101][2][1001];
        int dp(int i, bool buy, int k, vector<int>& prices){
         if(i==prices.size()) return 0;
         if(memo[i][buy][k]!=-1) return memo[i][buy][k];   
        int ans=dp(i+1, buy, k, prices);
        if(k==0) return 0;
        if(buy){
            ans=max(ans, -prices[i]+dp(i+1, false, k, prices));
        }    
        else{
            ans=max(ans, prices[i]+dp(i+1, true, k-1, prices));
        }
        return memo[i][buy][k]=ans;
        }
        int maxProfit(int k, vector<int> &prices){
            memset(memo,-1, sizeof(memo));
            return dp(0, true, k, prices);
        }

};
int main(){
    Solution solution;
    vector<int> prices={3,3,5,0,0,3,1,4};;
    cout<<solution.maxProfit(2, prices);
}