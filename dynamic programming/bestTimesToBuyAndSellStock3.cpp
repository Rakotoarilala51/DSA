#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<vector<int>>> memo;
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            this->memo.resize(n, vector<vector<int>>(3, vector<int>(2, -1)));
            return dp(0, 2, 1, prices);
        }
        int dp(int i, int k, bool buy, vector<int>& prices){
            if(i==prices.size()) return 0;
            if(k==0) return 0;
            if(memo[i][k][buy]!=-1) return memo[i][k][buy];
            int profit = dp(i+1, k, buy, prices);
            //profit = max(profit,dp(i+1, k, buy, prices));
            
            if(buy){
                profit = max(profit, -prices[i]+dp(i+1, k, 0, prices));
            }
            if(!buy){
                profit = max(profit,prices[i] + dp(i+1, k-1, 1, prices));
            }
            

            return memo[i][k][buy]=profit;
        }
    };
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution sol;
    cout<<sol.maxProfit(prices);
}