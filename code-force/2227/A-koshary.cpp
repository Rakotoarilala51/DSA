#include<bits/stdc++.h>
using namespace std;
bool canReach(int a, int b){
    if(a&1 & b&1) return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(canReach(a,b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}