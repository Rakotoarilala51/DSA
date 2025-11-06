#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> sieve(int n){
    vector<int> isPrime(n+1,1);
    isPrime[0]=isPrime[1]=0;
    for(int i=2; i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j=j+i){
                isPrime[j]=0;
            }
        }
    }
    return isPrime;
}

int32_t main(){
    int n=1000;
    vector<int> result;
    vector<int> prime = sieve(n*8);

    for(int i=0; i<=prime.size(); i++){
        if(prime[i]) result.push_back(i);
    }
    cout<<result[n];
}