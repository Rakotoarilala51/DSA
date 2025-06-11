#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n, m;
bool hamiltonian_path=false;
vector<int> gr[N];
int vis[N];
void path(int cur, int cnt){
    if(cnt==n){
        hamiltonian_path=true;
        return;
    }

    vis[cur]=1;
    for(auto x: gr[cur]){
        if(!vis[x]){
            path(x, cnt+1);
        }
    }
    vis[cur]=0;
    return;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        path(i,1);
    }
    cout<<hamiltonian_path;
}