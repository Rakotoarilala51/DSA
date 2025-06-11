#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int vis[N];
vector<int> backtrack(int& n, int cur, int cnt, unordered_set<int>& perfectSquare, vector<vector<int>>& adj, vector<int>& path, vector<int> visited){
    path.push_back(cur);
    visited[cur]=1;
    if(cnt==n){
        return path;
    }

    for(auto x: adj[cur]){
        if(!visited[x]){
        auto res=backtrack(n, x, cnt+1, perfectSquare, adj,path, visited);
        if(!res.empty()) return res;
    }
    }
    path.pop_back();
    visited[cur]=0;
    return {};
}
vector<int> squareSum(int n){
    unordered_set<int> perfectSquare;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<=2*n; i++){
        perfectSquare.insert(i*i);
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(perfectSquare.count(i+j)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int start=1; start<=n; start++){
    vector<int> visited(n+1,0);
    vector<int> path;
    auto res=backtrack(n,start,1,perfectSquare,adj,path, visited);
    if(!res.empty()) return res;
    }
    return {};
  
}
int main(){
    int n=15;
    vector<int> result=squareSum(20);
        for(int x: result){
            cout<<x<<" ";
        }
    
}