#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    if(n%3==0) return 0;
    else if(n%3==1) return 2;
    else return 1;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}