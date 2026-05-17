class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int z = 0;
        for (int i : nums) z += i>=0;
        if (!z || !(k %= z)) return nums;
        queue<int> q;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] >= 0) {
                q.push(nums[i]);
                while (q.size() > k) {
                    nums[i] = q.front();
                    q.pop();
                }
            }
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] >= 0) {
                nums[i] = q.front();
                q.pop();
                if (q.empty()) return nums;
            }
        }
        return nums;
    }
};