#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string a;
        int n;
        while(ss>>a){
            n=a.size();
        }
        return n;
    }
};
int main(){
    Solution solution;
    string s= "   fly me   to   the moon  ";
    cout<<solution.lengthOfLastWord(s);
}