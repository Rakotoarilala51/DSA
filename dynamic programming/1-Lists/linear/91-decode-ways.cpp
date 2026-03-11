#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> memo;
    int numDecodings(string s) {
        memo.resize(s.size()+1, -1);
        return dp(0, s);
    }
    int dp(int i, string& s){
        if(i==s.size()) return 1;
        if(memo[i]!=-1) return memo[i];
        int ans=0;
        if(s[i]>'0'){
            ans+=dp(i+1, s);
        }
        if(i+1<s.size() && (s[i]=='1'  || (s[i]=='2' && s[i+1]<='6') )) ans+=dp(i+2, s);
        
        return memo[i]=ans;
    }
};

int main(){
    Solution solution;
    string s ="11111111111111111111111111111111111111";
    cout<<solution.numDecodings(s);
}