class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (j - 1 >= 0 && i - 1 >= 0)
                    grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
                else if (j - 1 >= 0)
                    grid[i][j] += grid[i][j - 1];
                else if (i - 1 >= 0)
                    grid[i][j] += grid[i - 1][j];

        return grid[n - 1][m - 1];
    }
};