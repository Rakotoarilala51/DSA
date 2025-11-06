#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=8;
    vector<int> dp(n+1,0);
    int sum = 0;
    dp[0]=1;
    for(int i=1; i<=n; i++){
        dp[i]=sum+1;
        sum+=dp[i];
    }
    cout<<dp[n]<<endl<<(1<<n-1);
}