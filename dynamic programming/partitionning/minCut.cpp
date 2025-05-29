#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        string s;
        bool isPalindrome(int i, int j){
            if(i==j) return true;
            if(i==j-1) return (s[i]==s[j]);
            return (s[i]==s[j]) && isPalindrome(i+1, j-1);
        }
        int dp(int i){
            if(i==s.size()) return 0;
            int ans=INT_MAX;
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(i, j)){
                    ans=min(ans, dp(j+1));
                }
            }
            ans+=1;
            return ans;
        }
        int minCut(string s){
            this->s=s;
            return dp(0);

        }
};
int main(){
    string s="aab";
    Solution solution;
    cout<<solution.minCut(s);
}