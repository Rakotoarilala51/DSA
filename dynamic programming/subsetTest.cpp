#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];

bool subsetSum(int index, int sum){
    if(index==-1) return (sum==0);
 
    bool ans=false;
    //include index
    if(sum>=a[index]){
        ans|=subsetSum(index, sum-a[index]);
    }
    //exclude index
    ans|=subsetSum(index-1, sum);
    return ans;
}
int main(){
    freopen("input.txt", "r", stdin);


    int sum, n;
    cin>>sum>>n;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<subsetSum(n-1, sum);
}