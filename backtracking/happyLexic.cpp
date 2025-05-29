#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        const int m = 3 << (n - 1);
        if (m < k) return "";
        int t[3][2] = {{1, 2}, {0, 2}, {0, 1}};
        string s(n, 'a');
        s[0] += (k > m / 3) + (k > 2 * m / 3);
        --k;
        for (int i = 1; i < n; ++i)
            s[i] += t[s[i - 1] - 97][(k & (1 << (n - i - 1))) > 0];
        return s;
    }
};
class Solution{
    public:
    string getHappyString(int n, int k){
        int i=k-1;
        string output="";
        vector<string> result;
        backtrack(n,0,output, result);
        if(i>result.size()) return "";
        return result[i];
    }
    void backtrack(int n, int i, string& output, vector<string>& result){
        if(i==n){
            result.push_back(output);
            return;
        }
        if(i==0 || (i>=1 && output[i-1]!='a')){
            output+='a';
            backtrack(n, i+1, output, result);
            output.pop_back();
        }
        if(i==0 || (i>=1 && output[i-1]!='b')){
            output+='b';
            backtrack(n, i+1, output, result);
            output.pop_back();
        }
        if(i==0 || (i>=1 && output[i-1]!='c')){
            output+='c';
            backtrack(n, i+1, output, result);
            output.pop_back();
        }
    }

};

int main(){
    Solution solution;
    cout<<solution.getHappyString(1,4)<<endl;
    
    

}