#include<iostream>
#include<vector>
#include<unordered_set>
#include<sstream>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string result;
        string token;
        while(ss>>token){
            string root;
            for(int i=0; i<token.size(); i++){
                root=token.substr(0,i+1);
                if(dict.count(root)){
                    break;
                } 
            }
            if(!result.empty()) result+=" ";
            result+=root;

        }
        cout<<result;
        return result;
    }
};
int main(){
    Solution solution;
    vector<string> dictionary={"a","b","c"};
    string sentence="aadsfasf absbs bbab cadsfafs";
    solution.replaceWords(dictionary, sentence);
}