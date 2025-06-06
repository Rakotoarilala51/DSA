#include<iostream>
#include<vector>
using namespace std;
vector<int> primeDivisor(int n){
    vector<int> primeFactor(n+1, 0);
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            primeFactor.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) primeFactor.push_back(n);
}