#include<bits/stdc++.h>
using namespace std;
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
const int dx[8] = {-1,-1,0,1,1,1,0,-1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};
    int count = 0;
    set<pair<int, int>> obsets;
    for(auto obstacle: obstacles){
        obsets.insert({obstacle[0]-1, obstacle[1]-1});
    }
for (int dir = 0; dir < 8; dir++) {
    int nx = r_q - 1 + dx[dir];
    int ny = c_q - 1 + dy[dir];
    while (nx >= 0 && ny >= 0 && nx < n && ny < n) {
        if (obsets.count({nx, ny})) {
 
            break;
        }
        count++;
        nx += dx[dir];
        ny += dy[dir];
    }
}
  

    return count; 
}
