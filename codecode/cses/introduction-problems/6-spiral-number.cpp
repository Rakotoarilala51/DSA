#include<bits/stdc++.h>
#define int long long
using namespace std;
void getPositionByline(int l, int c){
    if(!(l&1)) cout<<l*l-(c-1)<<endl;
    else cout<<((l-1)*(l-1)) + c<<endl;
}
void getPositionByCol(int l, int c){
    if(c&1) cout<<c*c-(l-1)<<endl;
    else cout<<((c-1)*(c-1))+l<<endl;
}
void solve(int l, int c){
    if(l>=c) getPositionByline(l,c);
    else if(c>l) getPositionByCol(l,c);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int l, c;
        cin>>l>>c;
        solve(l,c);
    }
}