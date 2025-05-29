#include<iostream>
#include<cctype>
using namespace std;
class Solution{
    public:
    string clearDigits(string s){
        string stack="";
        for(char c: s){
            if(isdigit(c)){
                if(!stack.empty()) stack.pop_back();
            }
            else stack.push_back(c);
        }
        return stack;

    }
};
int main(){
    Solution solution;
    string s="cb34";
    cout<<solution.clearDigits(s);
}