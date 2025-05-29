#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n, k, p;
    cin>>n>>k>>p;
    vector<vector<int>> a(n+1, vector<int>(k+1, 0));
    vector<vector<int>> pref(n+1, vector<int>(k+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k;j++){
            cin>>a[i][j];
            pref[i][j]=pref[i][j-1]+a[i][j];         
        }
    }
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            for(int x=0; x<=min(k, j); x++){
                dp[i][j]=max(dp[i][j], dp[i-1][j-x]+pref[i][x]);
            }
        }
    }
    return dp[n][p];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, z=1;
    cin>>t;
    while(z<=t){
        cout<<"case#"<<z++<<":"<<solve()<<endl;
    }

}