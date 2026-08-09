class Solution {
public:
    int dp[101][202][2];

    int helper(int i, int M, int turn, vector<int>& piles) {
        int n = piles.size();
        if (n == i) {
            return 0;
        }
        if (dp[i][M][turn] != -1) {
            return dp[i][M][turn];
        }

        if (turn == 0) {
            int maxi = INT_MIN;
            int sum = 0;
            for (int x = 1; x <= 2 * M; x++) {
                if (x + i - 1 >= n) {
                    break;
                }

                sum += piles[x + i - 1];
                int val = helper(i + x, max(M, x), 1 - turn, piles);
                maxi = max(maxi, sum + val);
            }
            return dp[i][M][turn] = maxi;
        }

        int mini = INT_MAX;
        int sum = 0;
        for (int x = 1; x <= 2 * M; x++) {
            if (x + i - 1 >= n) {
                break;
            }
            int val = helper(i + x, max(M, x), 1 - turn, piles);
            mini = min(mini, val);
        }
        return dp[i][M][turn] = mini;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof dp);

        return helper(0, 1, 0, piles);
    }
};