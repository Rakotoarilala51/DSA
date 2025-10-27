#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prices;
    vector<vector<vector<vector<int>>>> memo;
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        int n = this->prices.size();
        this->memo.resize(n, vector<vector<vector<int>>>(10E4+1,vector<vector<int>>(3, vector<int>(3,-1))));
        return dp(0,0,1,0);
    }
    int dp(int i, bool canBuy, int transaction){
        if(i==prices.size() || transaction) return profit-;
        if(this->memo[i][profit][canBuy][transaction]!=-1) return memo[i][profit][canBuy][transaction];
        int ans = dp(profit, i+1, canBuy, transaction);
        if(canBuy) ans = max(ans, dp(profit-prices[i], i+1, 0, transaction));
        if(!canBuy) ans = max(ans, dp(profit+prices[i], i+1,1, transaction+1));
        return ans =;
    }
};
int main(){
    vector<int> prices = {7,6,4,3,1};
    Solution solution;
    cout<<solution.maxProfit(prices);
}