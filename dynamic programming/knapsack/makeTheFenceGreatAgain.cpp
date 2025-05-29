#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        int fence[3][n];
        int cost[3][n];
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i];
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                fence[i][j]=a[j]+i;
                cost[i][j]=b[j]*i;
            }
        }
        int dp[3][n];
        dp[0][0]=cost[0][0];
        dp[1][0]=cost[1][0];
        dp[2][0]=cost[2][0];
 
        for (int j = 1; j < n; j++)
    {
        dp[0][j]=dp[1][j]=dp[2][j]=INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int i_ = 0; i_ < 3; i_++)
            {
                if (fence[i][j] != fence[i_][j - 1])
                {
                   
                    dp[i][j] = min(dp[i][j], dp[i_][j - 1]);
                }
            }
            dp[i][j]=dp[i][j]+cost[i][j];
        }
    }
    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << endl;
        
    }
}