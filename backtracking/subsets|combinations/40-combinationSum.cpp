#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> candidate, output;
    vector<vector<int>> result;
    int target;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidate=candidates;
        this->target=target;
        dfs(0,0);
        return result;
    }
    void dfs(int start, int sum){
        if(sum==target){
            result.push_back(output);
            return;
        }
        if(sum>target || start==candidate.size()){
            return;
        }
        for(int i=start; i<candidate.size(); i++){
            if(i>start && candidate[i]==candidate[i-1]) continue;
            output.push_back(candidate[i]);
            dfs(i+1, sum+candidate[i]);
            output.pop_back();
        }

    }
};
int main(){
    vector<vector<int>> result;
    Solution solution;
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    result=solution.combinationSum2(candidates, target);
    for(auto arr:result){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}