class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int zeroes = 0;

        int i = 0, j = 0, n = nums.size();
        int ans = 0;
        while (j < n) {
            zeroes += nums[j] == 0;

            while (zeroes > 1) {
                if (nums[i++] == 0) {
                    zeroes--;
                }
            }

            ans = max(ans, j - i+1);
            j++;
        }

        return ans-1;
    }
};