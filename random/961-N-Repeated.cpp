#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> frequency;
        for(int num: nums){
            if(frequency.count(num)) return num;
            frequency.insert(num);
        }
        return 0;
    }
};