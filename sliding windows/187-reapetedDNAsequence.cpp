#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_set<string> set;
            string sub="";
            unordered_set<string> ans;
            for(int right=0; right<s.size(); right++){
                sub+=s[right];
                if(right>=9){
                    if(set.find(sub)!=set.end()){
                        ans.insert(sub);
                    }
                    set.insert(sub);
                    sub.erase(sub.begin());
                }
            }
            return vector<string>(ans.begin(), ans.end());
        }
};
int main(){
    Solution solution;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = solution.findRepeatedDnaSequences(s);
    for(string x: ans){
        cout<<x<<endl;
    }
}