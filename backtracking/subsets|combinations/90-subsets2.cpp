#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> output;
    vector<int> nums;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums=nums;
        dfs(0);
        return result;
    }
    void dfs(int start){

        result.push_back(output);
       
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            dfs(i+1);
            output.pop_back();
        }
        return;

    }
};
int main(){
        Solution solution;
    vector<int> nums = {1,2,2};
    vector<vector<int>> rs=solution.subsetsWithDup(nums);
    for(auto arr:rs){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}