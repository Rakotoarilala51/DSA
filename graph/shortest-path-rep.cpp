#include<bits/stdc++.h>
using namespace std;
class Graph{
  int V;
  list<int>* l;
  
  public:
    Graph(int v){
        V=v;
        l= new list<int>[V];
    }
    
    void addEdge(int i, int j, bool undir = false){
        l[i].push_back(j);
        if(undir) l[j].push_back(i);
    }
    void shortestPat(int source, int destination =-1){
        queue<int> q;
        bool* visited = new bool[V]{0};
        int* distance = new int[V]{0};
        int* parents = new int[V]{-1};
        
        q.push(source);
        visited[source] = true;
        
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto nbrs: l[f]){
                if(!visited[nbrs]){
                    visited[nbrs] = true;
                    q.push(nbrs);
                    distance[nbrs]=1+distance[f];
                    parents[nbrs] = f;
                }
            }
        }
    }
};

int main(){
    
}