#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:
        Graph(int v){
            V=v;
            l = new list<int>[V];
        }  
        
        void addEdge(int i, int j, bool undir=false){
            l[i].push_back(j);
            if(undir) l[j].push_back(i);
        }
        void dfsHelper(int source, bool *visited){
            visited[source] = true;
            
            for(int nbr:l[source]){
                if(!visited)dfsHelper(nbr, visited);
            }
        }
        void dfs(int source){
            bool *visited = new bool[V]{0};
            dfsHelper(source, visited);
        }
};