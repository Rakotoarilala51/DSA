#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string result="";
        for(char c: s){
            if(result.back()==c) result.pop_back();
            else result.push_back(c);
        }
        return result;
    }
};
int main(){
    string s="abbaca";
    Solution solution;
    cout<<solution.removeDuplicates(s);
}