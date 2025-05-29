#include<bits/stdc++.h>
using namespace std;
#define N 2000
int s[N], v[N];

int knapsack(int index, int size){
    if(index==-1) return 0;
    int ans=0;
    //include it
    if(s[index]<=size){
        ans=knapsack(index-1, size-s[index])+v[index];
    }
    //exclude it
    ans=max(ans, knapsack(index-1, size));
    return ans;

}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size,n;
    cin >>size>>n;

    for(int i=0; i<n; i++){
        cin>>s[i]>>v[i];
    }
    cout<<knapsack(n-1, size);

}