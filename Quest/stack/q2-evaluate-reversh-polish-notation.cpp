#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isInt(string s) {
        if (s.empty()) return false;

        int i = 0;
        if (s[0] == '-' || s[0] == '+') i++;

        if (i == s.size()) return false;

        for (; i < s.size(); i++) {
            if (!isdigit(s[i])) return false;
        }

        return true;
    }
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
        unordered_set<string> {"+","-","/","*"};
        for(string s: tokens){
            if(isInt(s)) tokenNumber.push(stoi(s));
        }
    }
};
int main(){
    
}