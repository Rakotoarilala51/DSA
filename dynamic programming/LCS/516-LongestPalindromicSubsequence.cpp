#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int longestPalindromicSubseq(string s){
        string reversed=s;
        reverse(reversed.begin(), reversed.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return lcs(0,0, s,reversed, dp);
    }
    int lcs(int i, int j,string& s1, string& s2, vector<vector<int>>& dp){
        if(i==s1.size() or j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+lcs(i+1,j+1, s1,s2, dp);
        return dp[i][j]=max(lcs(i, j+1, s1, s2, dp), lcs(i+1, j, s1, s2, dp));   
    }
};
int main(){
    Solution solution;
    cout<<solution.longestPalindromicSubseq("bbbab");
}