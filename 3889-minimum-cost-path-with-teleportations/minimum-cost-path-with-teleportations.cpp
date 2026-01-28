class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int range = 10000;

        vector<vector<vector<int>>> dp(
            k + 1, vector<vector<int>>(n, vector<int>(m, 1e9)));

        vector<int> bestPrefix(range + 1, 1e9);

        for (int p = 0; p <= k; p++) {
            vector<int> bestCurrent(range + 1, 1e9);

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) {
                        dp[p][i][j] = 0;
                    } else {
                        int ans = 1e9;

                        if (i + 1 < n) {
                            ans = min(ans, grid[i + 1][j] + dp[p][i + 1][j]);
                        }

                        if (j + 1 < m) {
                            ans = min(ans, grid[i][j + 1] + dp[p][i][j + 1]);
                        }

                        if (p > 0) {
                            ans = min(ans, bestPrefix[grid[i][j]]);
                        }

                        dp[p][i][j] = ans;
                    }
                    bestCurrent[grid[i][j]] =
                        min(bestCurrent[grid[i][j]], dp[p][i][j]);
                }
            }
            fill(bestPrefix.begin(), bestPrefix.end(), 1e9);
            bestPrefix[0] = bestCurrent[0];
            for (int r = 1; r <= range; r++) {
                bestPrefix[r] = min(bestPrefix[r - 1], bestCurrent[r]);
            }
        }

        return dp[k][0][0];
    }
};