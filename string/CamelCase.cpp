#include<bits/stdc++.h>
using namespace std;
int camelCase(string s){
    if(s.empty()){
        return 0;
    }
    int count = 1;
    for(char c: s){
        if(isupper(c)) count++;
    }
    return count;
}
int main(){
    cout<<camelCase("oneTwoThree");
}