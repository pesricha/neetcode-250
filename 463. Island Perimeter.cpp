#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row, col;
        row = grid.size();
        col = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    perimeter+=4;
                    if (i > 0 and grid[i-1][j] == 1) perimeter -= 2;
                    if (j > 0 and grid[i][j-1] == 1) perimeter -= 2;
                }   
            }
        }
        return perimeter;
    }   
};
