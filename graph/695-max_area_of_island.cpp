#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<bool>>& visited, vector<vector<int>>grid, int i, int j, int m, int n){
        visited[i][j]=true;
        int cs=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0; k<4; k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and nx>=0 and ny<n and nx<m and grid[nx][ny]==1 and !visited[nx][ny]){
                cs+=dfs(visited, grid, nx, ny, m,n);
            }
        }
        return cs;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int largest = 0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; i++){
                if(!visited[i][j] and grid[i][j]==1){
                    int size = dfs(visited, grid, i,j, m,n);
                    largest=max(largest, size);
                }
            }
        }
        return largest;
    }
};