#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
        string st;
        unordered_set<string> dict;
        vector<string> wordBreak(string s, vector<string>& wordDict){
            this->dict=unordered_set<string>(wordDict.begin(), wordDict.end());
            this->st=s;
            return dp(0);
        }
        vector<string> dp(int i){
            if(i==st.size()) return vector<string>{""};
            vector<string> ans;
            for(int j=i; j<st.size(); j++){
                if(dict.find(st.substr(i, j-i+1))!=dict.end()){
                    vector<string> res = dp(j+1);
                    string substring = st.substr(i, j-i+1);

                    for(auto& x:res){
                        x.insert(0, substring + (x.empty()?"":" "));
                        ans.push_back(x);
                    }
                }
            }
            return ans;
        }
};
int main(){
    Solution sol;
    vector<string> wordDict={"cats","dog","sand","and","cat"};
    string s ="catsanddog";
    vector<string> res = sol.wordBreak(s, wordDict);
    for(auto& stri: res){
        cout<<stri<<endl;
    }
}