#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumSum(vector<int>& nums)
    {
        
        unordered_map<int, int> map;
        int result = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int value=nums[i];
            while (value)
            {
                sum += value % 10;
                value /= 10;
            }
            auto it = map.find(sum);
            if (it != map.end())
            {
                int& index = it->second;
                result = max(result, nums[i] + nums[index]);
                if (nums[i] > nums[index])
                {
                    it->second = i;
                }
            }
            else{
                map[sum] = i;
            }
            

            
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {120, 12, 21, 14, 7};
    cout << solution.maximumSum(nums);
}