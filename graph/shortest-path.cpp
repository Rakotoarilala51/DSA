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
        
        void shortestPath(int source, int end = -1){
            queue<int> q;
            bool* visited = new bool[V]{0};
            int *dist = new int[V]{0};
            int *parent = new int[V]{-1};
            q.push(source);
            visited[source] = true;
            dist[source] = 0;
            while(!q.empty()){
                int f = q.front();
                cout<<f<<endl;
                q.pop();
                
                for(auto x: l[f]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                        dist[x] = dist[f] + 1;
                        parent[x] = f;
                        
                    }
                }
            }
            
        }
};
int main(){
    
}