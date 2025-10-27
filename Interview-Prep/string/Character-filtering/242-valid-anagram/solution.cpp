#include<iostream>
#include<vector>
#include<sstream>
#include<cctype>
using namespace std;
class Solution {
    private:
        int getIndexInAlphabet(char c){
            return c >='a' ? c -'a': c - 'A';
        }
    public:
        bool isAnagram(string s, string t) {
            vector<int> frequency(26,0);
            for(int i=0; i<s.size(); i++){
                if(isalpha(s[i])) frequency[getIndexInAlphabet(s[i])]++;
            }
            for(int i=0; i<t.size(); i++){
                if(isalpha(t[i])) frequency[getIndexInAlphabet(t[i])]--;
            }
            for(int j=0; j<26; j++){
                if(frequency[j]!=0) return false;
            }
            return true;
        }
};
int main(){
    Solution solution;
    string input, s, t;
    getline(cin, input);
    stringstream ss(input);
    getline(ss, s, ',');
    getline(ss,t);
    cout << s << " et " << t;
    if (solution.isAnagram(s, t)) cout << " sont des anagrammes ✅";
    else cout << " ne sont pas des anagrammes ❌";
    cout<<endl;
}