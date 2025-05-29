#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n;
   cin>>n;
   int cost[3][n];
   for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
        cin>>cost[i][j];
    }
   } 
   int dp[3][n];
   dp[0][0]=cost[0][0];
   dp[1][0]=cost[1][0];
   dp[2][0]=cost[2][0];
   for(int j=1; j<n; j++){
    dp[0][j]=min(dp[1][j-1], dp[2][j-1])+cost[0][j];
    dp[1][j]=min(dp[0][j-1], dp[2][j-1])+cost[1][j];
    dp[2][j]=min(dp[1][j-1], dp[0][j-1])+cost[2][j];
   }
   cout<<min({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
}