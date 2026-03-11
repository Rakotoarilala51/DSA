#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> total(m,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            total[i]+=x;
        }
    }
    int index=0, sum=INT_MIN;
    for(int i=0; i<total.size(); i++){
        if(total[i]>sum){
            index=i;
        }
    }
    cout<<index+1<<" "<<total[index];
}