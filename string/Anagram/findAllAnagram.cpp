#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> map;
        unordered_map<char, int> freq;
        int left=0;
        for(char c:p){
            map[c]++;
        }
        for(int right=0; right<s.size(); right++){
            freq[s[right]]++;
            if(right-left+1>=p.size()){
                if(freq==map) result.push_back(left);
                freq[s[left]]--;
                if(freq[s[left]]==0) freq.erase(s[left]);
                left++;
            }
        }
        return result;
        
    }
};
int main(){
    Solution solution;
    vector<int> result;
    string s = "abab", p = "ab";
    result=solution.findAnagrams(s,p);
    for(int num: result){
        cout<<num<<endl;
    }
}