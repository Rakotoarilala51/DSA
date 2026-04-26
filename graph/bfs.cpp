#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list<int> *l;
  
  public:
    Graph(int v){
        V = v;
        l = new list<int>[v];
    }
    
    void addEdge(int i, int j, bool undirected = true){
        l[i].push_back(j);
        if(undirected) l[j].push_back(i);
    }
    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int f = q.front();
            cout<<f<<endl;
            q.pop();
            for(auto x: l[f]){
                if(!visited[x]){ 
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,5);
    g.addEdge(3,4);
    g.bfs(1);
    return 0;
}