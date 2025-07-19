#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> sMap(26,0);
        for(int i=0; i<s.size(); i++){
            sMap[s[i]-'a']++;
            sMap[t[i]-'a']--;
        }
        for(int j=0; j<26; j++){
            if(sMap[j]!=0) return false;
        }
        return true;
    }
};