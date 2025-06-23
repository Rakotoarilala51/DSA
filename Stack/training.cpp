#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            switch (c)
            {
            case '(':
            case '{':
            case '[':st.push(c);
                break;
            case ')': if(!st.empty() and st.top()=='('){
                        st.pop();
                        }else{
                            return false;
                        }
                        break;
            case '}': if(!st.empty() and st.top()=='{'){
                        st.pop();
                        }else{
                            return false;
                        }
                        break;
            case ']': if(!st.empty() and st.top()=='['){
                        st.pop();
                        }else{
                            return false;
                        }
                        break;              
            default:
                continue;
            }
        }
        return st.empty();
    }
};
int main(){
    Solution solution;
    string s="()[]{}";
    cout<<solution.isValid(s);
}