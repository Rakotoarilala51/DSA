#include<bits/stdc++.h>
using namespace std;

vector<int> crible(int n){
    vector<int> result(n+1,0);
    for(int i=1; i<=n; i++){
        for(int j=i+i; j<=n; j=j+i){
            result[j]+=i;
        }
    }
    return result;
}
int main(){
    vector<int> result = crible(10000);
    for(int i=1;i<=10000; i++ ){
       if(result[i]==i){
            cout<<i<<" "<<result[i]<<endl;
       }
    }
}