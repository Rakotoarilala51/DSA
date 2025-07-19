#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool isAnagram(string s, string t){
        if(s.size()!=t.size()) return false;
        vector<int> frequency(26,0);
        for(int i=0; i<s.size(); i++){
            frequency[s[i]-'a']++;
            frequency[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(frequency[i]!=0) return false;
        }
        return true;
    }
};
int main(){
    Solution solution;
    string s= "anagram", t = "nagaram";
    cout<<solution.isAnagram(s,t);
}