#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes(int n){
    vector<int> is_prime(n+1, 1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            for(int j=1LL*i*i; j<=n; j+=i){
                cout<<j<<endl;
                is_prime[j]=0;
            }
        }
    }
    return is_prime;
}


int32_t main(){
    vector<int> is_prime=primes(1000000000);
    for(int num:is_prime){
        cout<< num<<" ";
    }
}