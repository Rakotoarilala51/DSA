#include <bits/stdc++.h>
#define int long long
using namespace std;
class Solution
{
public:
    vector<int> memo;
    int numSquares(int n)
    {
        vector<int> perfectSquares;
        for (int i = 1; i * i <= n; i++)
        {
            perfectSquares.push_back(i * i);
        }
        memo.resize(n + 1, -1);
        return dp(n, perfectSquares);
    }
    int dp(int n, vector<int> &perfectSquares)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MAX;
        if (memo[n] != -1)
            return memo[n];
        int ans = INT_MAX;
        for (int i = 0; i < perfectSquares.size(); i++)
        {
            ans = min(ans, 1 + dp(n - perfectSquares[i], perfectSquares));
        }
        return memo[n] = ans;
    }
};

int perfectSquare(int n)
{
}
int32_t main()
{

}