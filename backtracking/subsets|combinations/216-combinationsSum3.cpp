#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> output;
    int target, k;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->target=n;
        this->k=k;
        dfs(1,0);
        return result;
    }
    void dfs(int start, int sum){
        if(start>10) return;
        if(output.size()==k){
            if(sum==target){
            result.push_back(output);
            }
            return;
        }
        dfs(start+1, sum);
        output.push_back(start);
        dfs(start+1, sum+start);
        output.pop_back();
        return;

    }
};
int main(){
    Solution solution;
    vector<vector<int>> result=solution.combinationSum3(9,45);
        for(auto arr:result){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}