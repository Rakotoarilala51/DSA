#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int N;
    void primeFactor(int n){
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                int cnt=0;
                while(n%i==0){
                    cnt++;
                    n/=i;
                }
                cout<<i<<"^"<<cnt<<endl;
            }
            
        }
        if(n!=1){
            cout<<n<<"^"<<1<<endl;
        }
    }
    int countPrimes(int n){
        if(n<2) return 0;
        this->N=n;
        vector<int> sieve(N, 1);
        generateSieve(sieve);
        return count(sieve.begin(), sieve.end(), true);

    }
    void generateSieve(vector<int>& sieve){
        sieve[0]=sieve[1]=0;
        for(int i=0; i<=N;i++){
            if(sieve[i]){
                for(long long j=1LL*i*i; j<=N; j+=i){
                    sieve[j]=0;
                }
            }
        }
    }
};
int main(){
    Solution solution;
    solution.primeFactor(93);
}