#include<bits/stdc++.h>
using namespace std;
void permute(int i, string s){
    if(i== s.size()){
        cout<<s<<endl;
        return;
    }
    for(int j=i; j<s.size(); j++){
        swap(s[i], s[j]);
        permute(i+1, s);
        swap(s[i], s[j]);
    }
}
int main(){
    string a="abc";
    permute(0, a);
}