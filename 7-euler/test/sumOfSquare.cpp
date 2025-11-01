#include<bits/stdc++.h>
using namespace std;
int dp(int i){
    if(i==1) return 1;
    return dp(i-1)+((i)*(i));
}
int d(int n){
    return n*(n+1)*(2*n+1)/6;
}
int main(){
    cout<<d(1000)<<endl;

    
}