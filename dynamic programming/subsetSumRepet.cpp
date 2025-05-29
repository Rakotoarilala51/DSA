#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int sum, n;
    cin>>sum>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1; i<n; i++){
        cin>>a[i];
    }
    bool dp[n+1][sum+1];
    dp[0][0]=true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j]|=dp[i-1][j];
            if(j-a[i]>=0){
                dp[i][j]|=dp[i-1][j-a[i]];
            }
        }
    }
     cout<<dp[n][sum]<<endl;
    bool dp2[2][sum+1];
    dp2[0][0]=true;
    for(int j=0; j<=sum; j++){
        dp[0][j]=false;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp2[1][j]=dp2[0][j];
            if(j-a[i]>=0){
                dp2[1][j]|=dp2[0][j-a[i]];
            }
            
        }
        for(int j=0;j<=sum; j++){
            dp2[0][j]=dp2[1][j];
        }
    }
    cout<<dp2[1][sum]<<endl;
    int dp3[sum+1];
    dp3[0]=true;
    for(int j=1; j<=sum; j++){
        dp3[j]=false;
    }
    for(int i=1; i<=n; i++){
        for(int j=sum; j>=0; j--){
            if(j-a[i]>=0){
                dp3[j]|=dp3[j-a[i]];
            }
        }
    }
    cout<<dp3[sum];
}