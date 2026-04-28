#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);
        int curr = 1;

        queue<int> q;
        q.push(1);
        
        int destination;
        vector<int> level(n * n + 1, -1);
        level[1] = 0;

        for (int rows=n-1; rows>=0; rows--) {
            for (const int& col : cols) {
                cells[curr] = make_pair(rows, col);
                curr++;
            }
            reverse(cols.begin(), cols.end());
        }

        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (int next=curr+1; next<=min(curr+6, n*n); next++) {
                auto[i, j] = cells[next];
                destination = board[i][j] != -1 ? board[i][j] : next;
                if (level[destination] == -1) {
                    level[destination] = level[curr] + 1;
                    q.push(destination);
                }
            }
        }

        return level[n*n];
        
    }
};

