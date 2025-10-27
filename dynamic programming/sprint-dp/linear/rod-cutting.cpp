#include<bits/stdc++.h>
using namespace std;
int rodCutting(int n, vector<int>& price){
    return dp(n, price);
}
int dp(int n,  vector<int>& price){
    if(n==0) return 0;

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, price[i] + rodCutting(n-i, price));
    }  
    return ans; 
}
int main(){

}