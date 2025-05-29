#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int, int> dp;
    for(int i=0; i<n; i++){
        dp[a[i]]=dp[a[i]-1]+1;
    }
    int k=0;
    for(auto x:dp){
        //k=max(x.second, k);
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<k;
}