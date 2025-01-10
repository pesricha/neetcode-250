#include<bits/stdc++.h>
using namespace std;

/*
Intuitive: Initialize first row and first column to be 1.
Then the steps to point will be thge sum of upper and left point.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n,0));
        for (int i = 0 ; i < m; i++) grid[i][0] = 1;
        for (int j = 0 ; j < n; j++) grid[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n ; j++)
            {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }

        return grid[m-1][n-1];
    }
};