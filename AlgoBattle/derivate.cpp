#include<bits/stdc++.h>
using namespace std;
vector<int> sieve;
void primeSieve(){
    sieve[0]=sieve[1]=0;
    for(long long i=2; i<=10000; i++){
        if(sieve[i]){
            for(long long j=i*i; j<=10000; j+=i){
                sieve[j]=0;
            }
        }
    }
}
vector<int> primeOptimized(int n){
     vector<int> primeFactor(n+1, 0);
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            primeFactor[i]+=cnt;
        }
    }
    if(n!=1){
        primeFactor[n]=1;
    }
    return primeFactor;
}
int derivate(int x){
    if(sieve[x]){
        cout<<"1"<<endl;
        return 0;
    }
    vector<int> nums=primeOptimized(45);
    return 0;
}
int main(){
    vector<int> nums=primeOptimized(45);
    for(int num:nums){
        cout<<num<<" ";
    }
}