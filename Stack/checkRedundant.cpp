#include<iostream>
#include<stack>
using namespace std;
bool containsRedundant(string s){
    stack<char> st;
    for(char c:s){
        if(c!=')'){
            st.push(c);
        }
        else{
            bool operator_found=false;
        while(!st.empty() and st.top()!='('){
            char top=st.top();
            if(top=='+' or top=='*' or top=='-' or top=='/'){
                operator_found=true;
            }
            st.pop();
        }
        st.pop();
        if(operator_found==false) return true;
        }

    }
    return false;
}
int main(){
    string s="((ax+b)+(c))";
    cout<<containsRedundant(s);

}