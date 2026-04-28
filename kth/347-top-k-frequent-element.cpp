#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        for(int num:nums){
            map[num]++;
        }
        vector<pair<int,int>>frequency(map.begin(), map.end());
        nth_element(frequency.begin(), frequency.begin()+(frequency.size()-k), frequency.end(), [](const auto& a, const auto& b){
            return a.second<b.second;
        });
        vector<int> result;
        for(int i=frequency.size()-k; i<frequency.size(); i++){
            auto it = frequency[i];
            result.push_back(it.first);
        }
        return result;
    }
};