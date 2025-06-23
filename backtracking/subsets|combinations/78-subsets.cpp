#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> arr, output;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->arr=nums;
        this->output={};
        backtracking(0);
        return result;
    }
    void backtracking(int i){
        if(i==arr.size()){
            result.push_back(output);
            return;
        }
        backtracking(i+1);
        output.push_back(arr[i]);
        backtracking(i+1);
        output.pop_back();
        return;
    }
    
};
int main(){
    Solution solution;
    vector<int> nums = {1,2,3};
    vector<vector<int>> rs=solution.subsets(nums);
    for(auto arr:rs){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}