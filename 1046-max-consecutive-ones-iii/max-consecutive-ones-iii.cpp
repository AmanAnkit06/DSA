class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       
        int zeroes = 0;
        int i = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            zeroes += nums[j] == 0;
            while (zeroes > k) {
                zeroes -= nums[i++] == 0;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};