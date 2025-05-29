#include<bits/stdc++.h>
using namespace std;
int dp(int min, int n){
    if(min==0) return 0;
    int ans = 0;
    for(int i=min; i<=n; i++){
         ans+=dp(i, n-1);
    }
    return ans;
}
int main(){

}