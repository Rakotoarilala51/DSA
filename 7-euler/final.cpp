#include<bits/stdc++.h>
using namespace std;
vector<int> sumOfDivisor(int n){
    vector<int> sod(n+1,1);
    sod[0]=0;
    for(int i=2; i<n;i++){
        for(int j=i*2; j<n; j+=i){
            sod[j]+=i;
        }
    }
    return sod;
}
int amicableSUm(int n){
    vector<int> sumOfDivisorList=sumOfDivisor(n);
    int sum=0;
    for(int i=2; i<n; i++){
        int sumDiv=sumOfDivisorList[i];
        if(sumDiv<n&& sumDiv!=i && sumOfDivisorList[sumDiv]==i ){ sum+=i; 
            cout<<sumDiv<<" "<< i<<" "<<sumOfDivisorList[sumDiv]<<endl;
        }
    }
    return sum;
}
int main(){
    cout<<amicableSUm(10000);
}