#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, 1);
        sieve[0]=sieve[1]=0;
        int count = 0;
        for(long long i=2; i<=n; i++){
            if(sieve[i]){
                count++;
                for(long long j=i*i; j<=n; j+=i){
                    sieve[j]=false;
                }
            }
        }
        return count;
    }
};
int main(){
    Solution Solution;
    cout<<Solution.countPrimes(2);
}