#include<iostream>
#include<vector>
using namespace std;
#define N 10000000
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
int primeQuerries(int a, int b, vector<int>& sieve){
    vector<int> csum(N,0);
    for(int i=2; i<=N; i++){
        csum[i]=csum[i-1]+sieve[i];
    }
    return csum[b]-csum[a];
}

int main(){
    vector<int> sieve(N,1);
    primeSieve(sieve);
    int a=0, b=100;
    cout<<primeQuerries(a, b, sieve);

}