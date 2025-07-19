#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> output, nums;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums=nums;
        dfs(0);
        return result;
    }
    void dfs(int start){
        result.push_back(output);
        for(int i=start; i<nums.size(); i++){
            if(nums[i]==nums[i-1] && i>start) continue;
            output.push_back(nums[i]);
            dfs(i+1);
            output.pop_back();
        }
    }
};
int main(){
    Solution solution;
    vector<int> nums={1,2,2};
    vector<vector<int>> result=solution.subsetsWithDup(nums);
    for(auto arr: result){
        for(int num:arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}