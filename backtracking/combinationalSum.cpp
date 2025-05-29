#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int> nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
    bool knapsack(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum & 1)
            return false;
        bool dp[nums.size() + 1][(sum / 2) + 1];
        dp[0][0] = true;
        for (int x = 1; x <= sum / 2; x++)
        {
            dp[0][x] = false;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                if (j >= nums[i - 1])
                {
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
                }

                dp[i][j] |= dp[i - 1][j];
            }
        }
        return dp[nums.size()][sum / 2];
    }
    bool verify(int i, int sum, int subsum, vector<int> nums)
    {
        if (i == nums.size() - 1)
            return (sum == subsum);
        if (this->memo[i][sum] != -1)
            return memo[i][sum];
        bool ans = false;
        ans |= verify(i + 1, sum - nums[i], subsum + nums[i], nums);
        ans |= verify(i + 1, sum, subsum, nums);
        return memo[i][sum] = ans;
    }
};
int main()
{
    vector<int> nun = {22, 8, 19, 30, 86, 46, 66, 74, 93, 66, 73, 58, 6, 3, 44, 10, 21, 4, 76, 100, 65, 11, 30, 87, 50, 39, 53, 51, 97, 60, 1, 2, 25, 66, 67, 87, 89, 13, 64, 63, 81, 80, 94, 5, 20, 75, 74, 80, 56, 32, 54, 75, 19, 28, 80, 25, 59, 96, 1, 12, 100, 81, 49, 33, 90, 13, 83, 31, 77, 41, 58, 64, 39, 62, 100, 42, 49, 43, 73, 90, 85, 72, 21, 79, 75, 79, 43, 88, 33, 98, 5, 27, 45, 24, 83, 53, 65, 65, 63, 100};
    vector<int> numm = {83, 22, 11, 15, 50, 78, 16, 38, 23, 77, 81, 16, 3, 72, 94, 53, 91, 73, 7, 74, 86, 12, 36, 51, 5, 80, 47, 68, 29, 71, 5, 16, 26, 4, 16, 26, 6, 8, 48, 93, 27, 10, 93, 61, 34, 50, 50, 82, 59, 10, 7, 94, 18, 5, 5, 97, 21, 9, 71, 72, 29, 87, 83, 31, 71, 61, 79, 49, 27, 18, 72, 55, 75, 1, 67, 54, 90, 87, 93, 49, 66, 8, 11, 85, 74, 50, 45, 33, 33, 85, 35, 86, 57, 26, 29, 64, 75, 73, 5, 71};
    vector<int> num = {1, 5, 11, 5};
    vector<int> nums = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 97};
    Solution solution;
    cout << solution.canPartition(numm);
}
