#include<bits/stdc++.h>
using namespace std;
#define N 1'000'000
vector<int> generate(){
    vector<int> primeSieve(N,1);
    primeSieve[0]=primeSieve[1]=0;
    for(long long i=2; i<=N; i++){
        if(primeSieve[i]){
            for(long long j=i*i; j<=N; j+=i){
                primeSieve[j]=0;
            }
        }
    }
    return primeSieve;
}
int ith_nondecomp_prime(int n){
    vector<int> sieve=generate();
    vector<int> nonDecomp;
    for(int i=3; i<=N; i++){
        if(sieve[i] && i%4==3){
            nonDecomp.push_back(i);
        }
    }
    return nonDecomp[n-1];

}
int main(){
    cout<<ith_nondecomp_prime(10);
}