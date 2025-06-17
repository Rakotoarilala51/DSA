#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool validParenthesis(string s){
    stack<char> st;
    for (char c : s){
        switch (c){
        case '(':
        case '{':
        case '[':
            st.push(c);
            break;
        case ')':
            if (!st.empty() and st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
            break;
        case '}':
            if (!st.empty() and st.top() == '{'){
                st.pop();
            }
            else{
                return false;
            }
            break;
        case ']':
            if (!st.empty() and st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
            break;
        default:
            continue;
        }
    }
    return st.empty();
}
int main(){
    string s="(ab+b)+c+[a+(a+b]";
    cout<<validParenthesis(s);
}