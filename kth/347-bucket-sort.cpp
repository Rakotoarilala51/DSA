#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> counts;
        counts.reserve(nums.size());
        
        int max_freq = 0;
        for(int num: nums) {
            counts[num]++;
            max_freq = max(max_freq, counts[num]);
        }

        vector<vector<int>> buckets(max_freq+1);
        for(const auto& [num, freq]: counts) {
            buckets[freq].push_back(num);
        }
        
        vector<int> result;
        result.reserve(k);

        for(int i = max_freq; i >=0 && result.size() < k; i--) {
            if(!buckets[i].empty()) {
                for(int num: buckets[i]) {
                    result.push_back(num);
                    if(result.size() == k) return result;
                }
            }
        }
        return result;
    }
};