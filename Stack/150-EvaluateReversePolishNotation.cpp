#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s:tokens){
            if(s=="+"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                int result=a+b;
                st.push(to_string(result));
            }
            else if(s=="*"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                int result=a*b;
                st.push(to_string(result));
            }
            else if(s=="/"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                int result=a/b;
                st.push(to_string(result));
            }
            else if(s=="-"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                int result=a-b;
                st.push(to_string(result));
            }
            else{
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};
int main(){
    Solution solution;
    vector<string>  tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<solution.evalRPN(tokens);
}