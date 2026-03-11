#include<bits/stdc++.h>
using namespace std;
int dp(int n){
    if(n<=1) return n;
    return dp(n>>1)+(n&1);
}
int main(){
    for(int i=0; i<=10; i++){
        cout<<dp(i)<<endl;
    }
}