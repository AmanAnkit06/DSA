class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();

        int ans = 0;
        int crtP = 1;
        while (j < n) {
            crtP *= nums[j];
            while (crtP >= k && i <= j) {
                crtP /= nums[i++];
            }
            ans += j - i + 1;
            j++;
        }

        return ans;
    }
};