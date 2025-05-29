#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> memo;
int dp(int min, int n){
    if(n==0) return 1;
    if(memo[min][n]!=-1) return memo[min][n];
    int ans=0;
    for(int i=min; i<=n; i++){
        ans+=dp(i, n-i);
    }
    return memo[min][n]=ans;
}
int main(){
    int n;
    n=20;
    memo.resize(n+1,vector<int>(n+1,-1));
    cout<<dp(1, n);
}