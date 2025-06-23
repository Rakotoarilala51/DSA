#include<iostream>
#include<vector>
using namespace std;
vector<int> primeDivisor(int n){
    vector<int> primeFactor(n+1, 0);
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            //primeFactor[i]++;
            while(n%i==0){
               
                n/=i;
                 primeFactor[i]++;
            }
        }
    }
    if(n>1) primeFactor[n]++;
    return primeFactor;
}
int main(){
    vector<int> prime=primeDivisor(45);
    for(int num: prime){
        cout<<num<<" ";
    }
}