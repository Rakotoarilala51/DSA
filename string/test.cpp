#include<iostream>
#include<cctype>
using namespace std;
int main(){
    string s="*5";
    s[0]=tolower(s[0]);
    cout<<s;
}