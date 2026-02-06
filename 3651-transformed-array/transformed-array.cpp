class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = ((i + nums[i]) % n + n) % n;

            ans.push_back(nums[k]);
        }

        return ans;
    }
};