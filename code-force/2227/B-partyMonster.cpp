#include<bits/stdc++.h>
using namespace std;
bool canObtainRegularBracket(string s){
    if(s.size()&1) return false;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')' & !st.empty()) st.pop();
        
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
    }
}