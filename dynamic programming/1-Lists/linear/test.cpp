#include<bits/stdc++.h>
using namespace std;
void dp(int n,vector<int>& subresult, vector<vector<int>>& result){
    if(n==0){
        result.push_back(subresult);
        return;
    }
    for(int i=1; i<=n; i++){
        subresult.push_back(i);
        dp(n-i, subresult, result);
        subresult.pop_back();
    }
}
int main(){
    vector<int> sub;
    vector<vector<int>> res;
    int n=4;
    dp(n, sub, res);
    for(auto sub:res){
        for(int i: sub){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}