#include<iostream>
#include<vector>
using namespace std;
int pairFriends(int n){
    if(n<=2) return n;

    return (pairFriends(n-1)+((n-1)*pairFriends(n-2)));
}
int main(){
    int n=8;
    cout<<pairFriends(n)<<endl;
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]= dp[i-1] + dp[i-2] * (i-1);
    }
    cout<<dp[n];
}