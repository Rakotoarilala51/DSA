#include<bits/stdc++.h>
using namespace std;
int dp(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return dp(n-1)+dp(n-2);
}
int main(){
    int n=7;
    cout<<dp(n);
}