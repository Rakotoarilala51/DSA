#include<bits/stdc++.h>
using namespace std;
int MAX=3'000'010;
vector<int> memo(MAX, -1);
int cycleLength(int n){
    if(n==1) return 1;
    if(memo[n]!=-1) return memo[n];
    if(n&1) return memo[n]=1+cycleLength(3*n+1);
    else return memo[n]=1+cycleLength(n>>1);
}
int main(){
    int i, j;
    int maximum=0;
    cin>>i>>j;
    for(int k=i; k<=j; k++){
        int t_max=cycleLength(k);
        maximum=max(maximum, t_max);
    }
    cout<<i<<" "<<j<<" "<<maximum<<endl;
    return 0;

}