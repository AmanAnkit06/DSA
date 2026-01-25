class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        int maxi = 0, mini = INT_MAX;
        if (k == 1)
            return 0;

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
            if (i - j == k - 1) {
                ans = min(ans, maxi - mini);
                mini = nums[j + 1];
                j++;
            }
        }

        return ans;
    }
};