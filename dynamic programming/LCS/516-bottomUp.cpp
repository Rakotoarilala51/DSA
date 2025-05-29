#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution{
    public:
        int longestPalindromicSubseq(string s){
            string reversed=s;
            int n=s.size();
            reverse(reversed.begin(), reversed.end());
            vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
            for(int i=1; i<=s.size(); i++){
                for(int j=1; j<=reversed.size(); j++){
                    if(s[i-1]==reversed[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
            return dp[n][n];
        }
};
int main(){
    Solution solution;
    cout<<solution.longestPalindromicSubseq("cbbd");
}