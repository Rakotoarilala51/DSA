#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 8 directions : N, NE, E, SE, S, SW, W, NW
const int dx[8] = {-1,-1,0,1,1,1,0,-1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};

int main() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        if (!line.empty())
            grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if (grid[x][y] != 'X') continue;

            for (int dir = 0; dir < 8; ++dir) {
                int nx = x, ny = y;
                string word = "";
                for (int step = 0; step < 4; ++step) {
                    if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                        break;
                    word += grid[nx][ny];
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if (word == "XMAS") count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
