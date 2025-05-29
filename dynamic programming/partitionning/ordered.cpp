#include<iostream>
#include<vector>
using namespace std;
int dp(int n){
    if(n==0) return 1;
    int ans=0;
    for(int i=1; i<=n; i++){
        ans+=dp(n-i);
    }
    return ans;
}
int dp2(int i, int n){
    if(n==0) return 1;
    int ans=0;
    for(int j=i; j<=n; j++){
        ans+=dp2(j, n-j);
    }
    return ans;
}
int dp3(int i, int n){
    if(n==0) return 1;
    if(i==n) return 1;
    if(i>n) return 0;
    int ans=0;
    ans=dp3(i, n-i)+dp3(i+1, n);
    return ans;
}
int main(){
    cout<<dp3(1,7);
}