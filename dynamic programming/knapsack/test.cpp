#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=3;
    int x=6;
    vector<int> w={2,3,4,2,4,5,2,3};
    vector<int> c={1,1,1,2,2,2,3,3};
    vector<unordered_set<int>> w1(m, unordered_set<int>());
    for(int i=0; i<c.size(); i++){
      w1[c[i]-1].insert(w[i]);
    }
    
    vector<vector<bool>> dp(m, vector<bool>(x+1, false));
    for(int i=0; i<=x; i++){
      if(w1[0].find(i)!=w1[0].end()){
        dp[0][i]=true;
      }
    }
    for(int i=1; i<m; i++){
      for(int j=1; j<=x; j++){
        for(int k:w1[i]){
          if(j-k>=1 && dp[i-1][j-k]){
            dp[i][j]=true;
            break;
          } 
        }
      }
    }
    cout<<dp[m-1][x];
    return 0;
    
}