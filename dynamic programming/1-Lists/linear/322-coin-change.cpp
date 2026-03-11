#include<bits/stdc++.h>
#define int long long
using namespace std;
class Solution {
public:
    vector<vector<long long>> memo;

    int coinChange(vector<int>& coins, int amount) {
        memo.assign(coins.size(), vector<long long>(amount + 1, -1));
        long long res = dp(0, amount, coins);
        return (res >= 1e18 ? -1 : (int)res);
    }

    long long dp(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (i == coins.size()) return 1e18; // impossible
        if (memo[i][amount] != -1) return memo[i][amount];

        long long ans = 1e18;

        // NOT TAKE
        ans = min(ans, dp(i + 1, amount, coins));

        // TAKE (unbounded)
        if (amount >= coins[i]) {
            ans = min(ans, 1 + dp(i, amount - coins[i], coins));
        }

        return memo[i][amount] = ans;
    }
};

int32_t main(){
    Solution solution;
    vector<int> coins = {1,2,5};
    cout<<solution.coinChange(coins, 11);
}