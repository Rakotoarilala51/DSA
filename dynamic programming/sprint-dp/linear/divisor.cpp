#include<bits/stdc++.h>
using namespace std;
long long intPow(long long base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

vector<int> generatePrimes(int maxN){
    vector<bool> isPrime(maxN+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=maxN; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=maxN; j+=i ){
                isPrime[j]= false;
            }
        }
    }
    vector<int> primes;
    for(int i=2; i<=maxN; i++){
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}
void productInt(int n, vector<int>& subr, vector<vector<int>>& result){
    if(n==1){
        result.push_back(subr);
        return;
    }
    for(int i=2; i<=n; i++){
        if(subr.size()>=1 and i<subr.back()) continue;
        if(n%i==0){
            subr.push_back(i);
            productInt(n/i, subr, result);
            subr.pop_back();
        }
    }
}

long long minimumNum(int n){
    vector<int> subresult;
    vector<vector<int>> result;
    vector<int> primes = generatePrimes(100);
    productInt(n, subresult, result);
    long long ans= LLONG_MAX;
    for(auto nums: result){
        long long k=1, primeIndex=0;
        for(int i=nums.size()-1; i>=0; i--){
            k*= intPow(primes[primeIndex], nums[i]-1);
            primeIndex++; 
        }
        ans = min(ans, k);
    }
    return ans;

}
int main(){
    cout<<minimumNum(100);
}