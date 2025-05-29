#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n1=word1.size();
            int n2=word2.size();
            vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
            for(int i=1; i<=n1; i++){
                for(int j=1; j<=n2; j++){
                    if(word1[i-1]==word2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
            return ((n1+n2)-(dp[n1][n2]*2));
            
        }
};
int main(){
    Solution solution;
    string word1="leetcode";
    string word2="etco";
    cout<<solution.minDistance(word1, word2);

}