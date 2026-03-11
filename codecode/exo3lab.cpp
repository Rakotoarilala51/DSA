#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    return 3-(n%3);
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}