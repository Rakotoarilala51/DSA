#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        string output="";
        backtracking(n, 0,result, output, 0,0);
        return result;
    }
    void backtracking(int n, int i,vector<string>& result, string &output, int open, int close){
        if(i==2*n){
            result.push_back(output);
            return;
        }
        if(open<n){
            output+='(';
            backtracking(n, i+1,result, output, open+1, close);
            output.pop_back();
        }
        if(close<open){
            output+=')';
            backtracking(n,i+1, result, output, open, close+1);
            output.pop_back();
        }
    }
};
int main(){
    Solution solution;
    vector<string> result=solution.generateParenthesis(3);
    for(string s: result){
        cout<<s<<endl;
    }
    return 0;
}