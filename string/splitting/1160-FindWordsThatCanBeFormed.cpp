#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canFormed(string& word, unordered_map<char, int>& freq){
        for(char c: word){
            if(!freq.count(c)) return false;
            freq[c]--;
            if(freq[c]==0) freq.erase(c);
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> frequency;
        int count=0;
        for(char c: chars){
            frequency[c]++;
        }
        for(string word: words){
            unordered_map<char, int> freq=frequency;
            if(canFormed(word, freq)) count+=word.size();
        } 
        return count;
    }
};
int main(){
    Solution solution;
    vector<string> word={"hello","world","leetcode"};
    string chars="welldonehoneyr";
    cout<<solution.countCharacters(word, chars);
}