#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(int a, int b, char op){
        int result =0;
        
        switch (op)
        {
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
        
        case '/':
            result = a/b;
            break;
        
        case '*':
            result = a*b;
            break;
        default:
            break;
        }
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenNumber;
        for(string s: tokens){
            if()
        }
    }
};
int main(){
    
}