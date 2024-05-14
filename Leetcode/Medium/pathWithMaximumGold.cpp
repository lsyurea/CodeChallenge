class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // mark visited as negative gold cannot visit <= 0
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    res = max(res, getMaxHelper(grid, i, j));
                }
            }
        }
        return res;
    }

    int getMaxHelper(vector<vector<int>>& grid, int i , int j) {
        if (grid[i][j] <= 0) return 0;
        grid[i][j] *= -1;
        int max_val = 0;
        if (i > 0) max_val = max(getMaxHelper(grid, i - 1, j), max_val);
        if (j > 0) max_val = max(getMaxHelper(grid, i, j - 1), max_val);
        if (i < grid.size() - 1) max_val = max(getMaxHelper(grid, i + 1, j), max_val);
        if (j < grid[0].size() - 1) max_val = max(getMaxHelper(grid, i, j + 1), max_val);
        grid[i][j] *= -1;
        return max_val + grid[i][j];
    }
};