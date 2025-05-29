#include<iostream>
#include<vector>
#include<stack> 
using namespace std;
class Solution{
    string smallestNumber(string pattern){
        string result;
        stack<char> stack{{'1'}};
        for(char c: pattern){
            char maxSofar=stack.top();
            if(c=='I'){
                while(!stack.empty()){
                    maxSofar=max(maxSofar, stack.top());
                    ans+=stack.top(), stack.pop();
                }
                
            }
            stack.push(maxSoFar+1);
        } 
        while(!stack.empty()){
            result+=stack.top(), stack.pop();
        }
        return result;
    }
};