#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        set<char> vowelSet = {'a','e', 'o', 'i', 'u'};
        map<char, int> vowelMap;
        stack<char> stack;
        for(char c: s){
            if(vowelSet.count(c)) vowelMap[c]++;
        }
        vector<pair<char, int>> vowelsVec(vowelMap.begin(), vowelMap.end());
        sort(vowelsVec.begin(), vowelsVec.end(), [s](auto& a, auto& b){
            if(a.second==b.second) return s.find(a.first)>s.find(b.first);
            return a.second<b.second;
        });
        for(auto x:vowelsVec){
            while(x.second--){
                stack.push(x.first);
            }
        }
        for(int i=0; i<s.size(); i++){
            if(vowelSet.count(s[i])){
                s[i]=stack.top();
                stack.pop();
            }
        }
        return s;
    }
};

int main(){
    Solution solution;
    cout<<solution.sortVowels("aaaaxiibeecaaaacuu");
}