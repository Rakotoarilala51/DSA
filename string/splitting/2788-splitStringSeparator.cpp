#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for(string word: words){
            stringstream ss(word);
            string token;
            while(getline(ss, token, separator)){
                if(!token.empty())result.push_back(token);
            }
        }
        return result;
    }
};