#include<iostream>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string stack= "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*') stack.pop_back();
            else stack.push_back(s[i]);
           
        }
        return stack;
        
    }
};
int main(){
    string s="aina";
    string stack="";
   
    Solution solution;
    cout<<solution.removeStars("lee**tco");
}