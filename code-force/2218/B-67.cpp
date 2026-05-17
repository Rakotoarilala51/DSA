#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
    
     int maximum=0;
     int sum=0;
     for(int i=0; i<7; i++){
        int a;
        cin>>a;
        sum+=a;
        maximum=max(maximum, a);
     }
     cout<<maximum*2-sum<<endl;
   } 
   return 0;
}