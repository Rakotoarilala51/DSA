#include<iostream>
using namespace std;
void primeFactorisation(int n){
    for(int i=2; i<=n; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
}
//optimized one's
void primeOptimized(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
    if(n!=1){
        cout<<n<<"^"<<1;
    }
}
int main(){
    primeOptimized(93);
}