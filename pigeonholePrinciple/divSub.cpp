#include<bits/stdc++.h>
using namespace std;
void findNonEmptySubset(int arr[], int N){
    unordered_map<int, int> mp;
    int sum=0;

    for(int i=0; i<N; i++){
        sum=(sum+arr[i])%N;

        if(sum==0){
            //print the size(remove it if useless)
            cout<<i+1<<endl;
            for(int j=0; j<=i; j++){
                cout<<j+1<<" ";
            }
             return;
        }

        if(mp.find(sum)!=mp.end()){
            //print the size again
            cout<<i-mp[sum]<<endl;
            for(int j=mp[sum]+1; j<=i; j++){
                cout<<j+1<<" ";
            }
            return;
        }
        else{
            mp[sum]=i;
        }
    }
}
int main(){
    int arr[]={1,3,4,2,7};
    int N= sizeof(arr)/sizeof(arr[0]);
    findNonEmptySubset(arr, N);
    return 0;
}