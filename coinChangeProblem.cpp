#include<bits/stdc++.h>
using namespace std;
long memo[51][251];
long dp(int i, int sum, int& n, vector<long>& c){
    if(i==c.size()) return (sum==n);
    long ans=0;
    if(memo[i][sum]!=-1) return memo[i][sum];
    if(sum+c[i]<=n) ans+=dp(i, sum+c[i],n,c);
    ans+=dp(i+1, sum, n, c);
    return memo[i][sum]=ans;
}
long getWays(int n, vector<long> c){
    memset(memo,-1, sizeof(memo));
    long ans =0;
    return dp(0, 0, n, c);
}

int main(){
    vector<long> c={2,5,3,6};
    cout<<getWays(10,c);
}