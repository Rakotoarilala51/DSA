#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, size;
    cin>>size>>n;
    int s[n+1],v[n+1];
    for(int i=1;i<=n; i++){
        cin>>s[i]>>v[i];
    }
    int knapsack[size+1];
    memset(knapsack, 0, sizeof(knapsack));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=size; j++){
            if(j-s[i]>=0)knapsack[j]=max(knapsack[j], knapsack[j-s[i]]+v[i]);
        }
    }
    cout<<knapsack[size];
}