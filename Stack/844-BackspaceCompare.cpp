#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> tt;
        for(char c:s){
            if(!st.empty() && c=='#') st.pop();
            else  if(c!='#') st.push(c);
        }
        for(char c:t){
            if(!tt.empty() && c=='#') tt.pop();
            else if(c!='#') tt.push(c);
        }
        while (!st.empty())
        {
           cout<<st.top()<<" ";
           st.pop();
        }
        cout<<endl;
        while (!tt.empty())
        {
           cout<<tt.top()<<" ";
           tt.pop();
        }
        cout<<endl;
        return st==tt;
    }
};
int main(){
    Solution solution;
    string s ="y#fo##f",t ="y#f#o##f";
    cout<<solution.backspaceCompare(s,t);
}