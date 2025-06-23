#include<vector>
#include<iostream>
using namespace std;
class Solution{
    public:
        vector<vector<int> > result;
        int n, k;
        vector<vector<int> > combination(int n, int k){
             vector<int> output;
            this->n=n;
            this->k=k;
            dfs(1, output);
            return result;
        }
        void dfs(int start, vector<int> output){
            if(output.size()==k){
                result.push_back(output);
                return;
            }

            for(int i=start; i<=n; i++){
                output.push_back(i);
                dfs(i+1, output);
                output.pop_back();
            }
            
            return;
        }
};
int main(){
        Solution solution;
    vector<int> nums = {1,2,2};
    vector<vector<int>> rs=solution.combination(8,3);
    for(auto arr:rs){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}