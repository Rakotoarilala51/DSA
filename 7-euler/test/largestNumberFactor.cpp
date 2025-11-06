#include<bits/stdc++.h>
using namespace std;
int largestPrimeFactor(int n){
    int factor=2;
    while(factor*factor>n){
        while(n%factor==0){
            n/=factor;
        }
        factor++;
    }
    return factor;
}
int main(){
    cout<<largestPrimeFactor(649);
}