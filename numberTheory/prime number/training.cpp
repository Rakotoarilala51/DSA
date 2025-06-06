#include<iostream>
#include<vector>
using namespace std;
#define N 1000000
void primeSieve(vector<int>& sieve){
    sieve[0]=sieve[1]=0;
    for(int i=2; i<=N; i++){
        if(sieve[i]){
            for(int j=i*i; j<=N; j=j+i){
                sieve[j]=0;
            }
        }
    }
}
int main(){
    
}