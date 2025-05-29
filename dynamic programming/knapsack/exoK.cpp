#include<bits/stdc++.h>
using namespace std;
#define N 2001
int s[N], v[N];
int knapsack(int index, int size){
    if(index==-1) return 0;
    int ans=0;
    //include the thing
    if(s[index]<=size){
        ans=v[index]+knapsack(index-1, size-s[index]);
    }
    //exclude the thing
    ans=max(knapsack(index-1, size), ans);
    return ans;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int size, n;
    cin>>size>>n;
    for(int i=0; i<n; i++){
        cin>>s[i]>>v[i];
    }
    cout<<knapsack(n-1, size);

}