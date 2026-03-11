#include<bits/stdc++.h>
using namespace std;
int dp(int n){
    if(n==1) return 2;
    if(n==2) return 3;
    return dp(n-1)+dp(n-2);
}
int main(){
    int n=5;
    vector<int> memo(n+1, 0);
    memo[1]=2;
    memo[2]=3;
    for(int i=3; i<=n; i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
    cout<<memo[n];
}