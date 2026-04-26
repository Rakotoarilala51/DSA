#include <bits/stdc++.h>
using namespace std;

class Graph{
   int V;
   list<int>* l;
   public:
        Graph(int v){
            V=v;
            l= new list<int>[V];
        }
        void addEdge(int i, int j){
            l[i].push_back(j);
        }
        
        int bfsMinCost(int source, int dest){
            queue<int> q;
            bool* visited = new bool[V]{0};
            int* distance = new int[V]{0};
            
            q.push(source);
            visited[source] = true;
            
            while(!q.empty()){
                int f = q.front();
                //cout<<f<<":";
                q.pop();
                for(auto nbrs: l[f]){
                    //cout<<nbrs<<" ";
                    if(!visited[nbrs]){
                        visited[nbrs] = true;
                        q.push(nbrs);
                        distance[nbrs] = 1+distance[f];
                    }
                }
                //cout<<endl;
            }
            
            return distance[dest];
        }
};
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> oneDBoard((n*n)+1, 0);
        Graph gr((n*n)+1);
        int counter = 1;
        bool increase = true;
        for (int line = n - 1; line >= 0; --line)
        {

            if (!increase)
            {
                for (int j = n - 1; j >= 0; --j)
                {
                    if (board[line][j] != -1)
                        oneDBoard[counter] = board[line][j];
                    counter++;
                }
            }
            else
            {
                for (int j = 0; j < n; ++j)
                {
                    if (board[line][j] != -1)
                        oneDBoard[counter] = board[line][j];
                    counter++;
                }
            }
            
        }
        for(int i=1; i<=n*n;i++){
            cout<<oneDBoard[i]<<" ";
        }
        for(int i=1; i<(n*n); i++){
           // cout<<"i:"<<i<<endl;
            for(int dice=1; dice<=6; dice++){
                int v = dice + i;
                v=oneDBoard[v];
               // cout<<"   "<<v<<endl;
                if(v<=(n*n)){
                    gr.addEdge(i,v);
                }
            }
        }
        return gr.bfsMinCost(1, n*n);
    }
};

int main()
{
    vector<vector<int>> board = {
    {-1, -1, 19, 10, -1},
    { 2, -1, -1,  6, -1},
    {-1, 17, -1, 19, -1},
    {25, -1, 20, -1, -1},
    {-1, -1, -1, -1, 15}
};
    Solution solution;
    cout<<solution.snakesAndLadders(board);
}