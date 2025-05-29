#include<iostream>
#include<vector>
using namespace std;
#define N 1000000
void primeSieve(vector<int>& sieve){
    sieve[0]=sieve[1]=0;
    for(long long i=2; i<=N; i++){
        if(sieve[i]){
            for(long long j=i*i; j<=N; j+=i){
                sieve[j]=0;
            }
        }
    }
}

int main(){
    vector<int> sieve(N, 1);
    primeSieve(sieve);
    for(int i=0; i<=1000; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
}