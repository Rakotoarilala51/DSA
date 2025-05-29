#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int count_even = 1;  
        int count_odd = 0;
        int prefixSum = 0;
        int total_odd = 0;
        int MOD = 1e9 + 7;

        for (int num : nums) {
            prefixSum += num;  

            if (!(prefixSum &1)) { 
                total_odd = (total_odd + count_odd) % MOD;
                count_even++;
            } else {
                total_odd = (total_odd + count_even) % MOD;
                count_odd++;
            }
        }

        return total_odd;
    }
};

int main() {
    vector<int> nums = {1,5,3}; 
    Solution solution;
    cout << solution.numOfSubarrays(nums) << endl;
    return 0;
}
