#include<bits/stdc++.h>
using namespace std;
string s;
int dp(int index, bool last, int sum){
    if(index==s.size()){
        return sum;
    }
    int till = last?s[index]-'0':9;
    int ans=0;
    for(int digit=0; digit<=till; digit++){
        ans+=dp(index+1, last && digit==till, sum+digit);
    }
    return ans;
}
int f(int _n){
    s=to_string(_n);
    return dp(0,1,0);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1){
        int a,b;
        cin>>a>>b;
        if(a==-1 && b==-1) break;
        cout<<f(b)-f(a-1)<<endl;
    }
 
    return 0;
}