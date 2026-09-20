class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int help(vector<vector<int>>& grid, int i, int j) {

        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }
        if (i >= n || j >= m) {
            return INT_MAX;
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }

        return dp[i][j] =
                   grid[i][j] + min(help(grid, i, j + 1), help(grid, i + 1, j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<int>(m, INT_MAX));

        return help(grid, 0, 0);
    }
};