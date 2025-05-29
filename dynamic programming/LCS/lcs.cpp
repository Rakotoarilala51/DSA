#include<iostream>
#include<vector>
using namespace std;
int lcs(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
    if(i==s1.size() or j==s2.size()){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1+lcs(i+1, j+1, s1, s2, dp);
    }
    int ops1=lcs(i, j+1, s1, s2, dp);
    int ops2=lcs(i+1, j, s1, s2, dp);
    return dp[i][j]=max(ops1, ops2);
}
int main(){
    string a="ABCSD";
    string b="ABECGD";
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    cout<<lcs(0,0,a,b, dp);
}