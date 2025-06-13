#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> frequency;
        for(char c: ransomNote){
            frequency[c]++;
        }
        for(char c: magazine){
            if(frequency.count(c)){
                frequency[c]--;
                if(frequency[c]==0){
                    frequency.erase(c);
                }
            }
        } 
        return frequency.empty()?true:false;      
    }
};
int main(){
    Solution solution;
    string ransomNote = "aa", magazine = "aab";
    cout<<solution.canConstruct(ransomNote, magazine);
}