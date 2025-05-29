#include<bits/stdc++.h>
using namespace std;
#define N 2001
int s[N], v[N];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int size,n;
    cin>>size>>n;
    s[0]=0;
    v[0]=0;
    for(int i=1; i<=n; i++){
        cin>>s[i]>>v[i];
    }
    vector<vector<int>> knapsack(n+1, vector<int>(size+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=size; j++){
            if(j>=s[i]) knapsack[i][j]=knapsack[i-1][j-s[i]]+v[i];
            knapsack[i][j]=max(knapsack[i][j], knapsack[i-1][j]);
            
        }
    }
    cout<<knapsack[n][size];
    return  0;

}