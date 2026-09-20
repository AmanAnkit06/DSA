class Solution {
public:
    vector<vector<int>> dp;
    int help(vector<int>& coins, int amount, int i) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0 || i >= coins.size()) {
            return 1e9;
        }
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int take = 1 + help(coins, amount - coins[i], i);
        int notTake = help(coins, amount, i + 1);
        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(), vector<int>(amount + 1, -1));
        int ans = help(coins, amount, 0);

        return (ans >= 1e9) ? -1 : ans;
    }
};