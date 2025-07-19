#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> output;
    vector<vector<int>> result;
    int n, k;
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        this->k=k;
        dfs(1);
        return result;
    }
    void dfs(int start){
        //if(start>n) return;
        if(output.size()==k){
            result.push_back(output);
            return;
        }
        for(int i=start; i<=n; i++){
            output.push_back(i);
            dfs(i+1);
            output.pop_back();
        }
        return;
    }

};
int main(){
    Solution solution;
    vector<vector<int>> result=solution.combine(5,3);
    for(auto arr:result){
        for(int num: arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}