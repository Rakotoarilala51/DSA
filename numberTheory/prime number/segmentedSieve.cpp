#include<iostream>
#include<vector>
using namespace std;
#define N 100000
int sieveArr[N+1]={0};
vector<int> primes;
void sieve(){
    for(long long i=2; i<=N; i++){
        if(sieveArr[i]==0){
            primes.push_back(i);
            for(long long j=i*i; j<=N; j+=i){
                sieveArr[j]=1;
            }
        }
    }
}
int main(){
    sieve();
   int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> segment(n-m+1,0);
        for(auto p: primes){
            //stop when p^2>n
            if(p*p>n){
                break;
            }
            //otherwise we need to find the nearest starting point
            int start=(m/p)*p;

            if(p>=m and p<=n){
                start=2*p;
            }
            //start marking the number as not prime from start
            for(int j=start; j<=n; j+=p){
                if(j<m){
                    continue;
                }
                //mark it as non prime
                segment[j-1]=1;

            }
        } 
        //primes stored as 0 int the segment
        for(int i=m; i<=m; i++){
            if(segment[i-m]==0){
                cout<<i<<endl;
            }
        }
            cout<<endl;    
        

    }
    return 0;
}