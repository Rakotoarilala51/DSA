#include<bits/stdc++.h>
using namespace std;
#define N 2001
int s[N], v[N];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int size, n;
    cin>>size>>n;
    s[0]=0;
    v[0]=0;
    for(int i=1; i<=n; i++){
        cin>>s[i]>>v[i];
    }
    vector<vector<int>>knapsack(2, vector<int>(size+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=size; j++){
            if(j>=s[i]) knapsack[1][j]=knapsack[0][j-s[i]]+v[i];
            knapsack[1][j]=max(knapsack[0][j], knapsack[1][j]);
        }
        for(int k=0; k<=size; k++){
            knapsack[0][k]=knapsack[1][k];
        }
    }
    cout<<knapsack[1][size];
}