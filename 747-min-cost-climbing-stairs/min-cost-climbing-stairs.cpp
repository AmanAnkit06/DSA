class Solution {
public:
    int helper(vector<int>& cost, int i,vector<int>&dp) {
        if (i >= cost.size()) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i] + min(helper(cost, i + 1,dp), helper(cost, i + 2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(helper(cost, 0,dp), helper(cost, 1,dp));
    }
};