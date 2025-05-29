#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    public:
        bool wordBreak(string s, vector<string>& wordDict){
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            vector<int> memo(s.size(), -1);

            return dp(0, s, dict, memo);
            
        }
        bool dp(int i, string& s, unordered_set<string>& dict, vector<int>& memo){
            if(i==s.size()) return true;
            if(memo[i]!=-1) return memo[i];
            for(int j=i; j<s.size();  j++){
                string word=s.substr(i, j-i+1);
                if(dict.find(word)!=dict.end()&& dp(j+1, s, dict, memo)){
                    memo[i]=true;
                    return true;
                }
            }
            memo[i]=false;
            return false;
        }
        
};
int main(){
    Solution solution;
    string s="aaaaaab";
    vector<string> wordDict= {"aaaa", "aaa"};
    cout<<solution.wordBreak(s, wordDict);

}