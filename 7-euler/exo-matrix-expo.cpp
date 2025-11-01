#include<bits/stdc++.h>
using namespace std;
#define int long long
int pow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int32_t main(){
    cout<<pow(215,400);
}