#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0; i<n-1; i++){
        int a;
        cin>>a;
        sum+=a;
    }
    int result=(n*(n+1)/2)-sum;
    cout<<result<<endl;
}