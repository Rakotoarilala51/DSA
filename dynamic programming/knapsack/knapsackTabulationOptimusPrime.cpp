#include<bits/stdc++.h>
using namespace std;
#define N 2001
int s[N], v[N];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, size;
    cin>>size>>n;
    for(int i=0;i<n; i++){
        cin>>s[i]>>v[i];
    }
    int knapsack[size+1];
    int dp[size+1];
    memset(dp,0, sizeof(dp));
    memset(knapsack, 0, sizeof(knapsack));
    for(int i=0; i<n; i++){
        for(int j=size; j>=0; j--){
            if(j-s[i]>=0)knapsack[j]=max(knapsack[j], knapsack[j-s[i]]+v[i]);
        }
    }
    cout<<knapsack[size];
}