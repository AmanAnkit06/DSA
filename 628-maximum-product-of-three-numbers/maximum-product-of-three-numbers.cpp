class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int prod = nums[i] * nums[j] * nums[k];
                ans = max(ans, prod);
                if (ans < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};