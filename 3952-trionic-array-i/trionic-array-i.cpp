class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = 0;
        if (nums.size() <= 3)
            return false;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                continue;
            } else if (nums[i] < nums[i - 1]) {

                p = i - 1;
                break;
            } else {
                return false;
            }
        }

        for (int i = p + 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                continue;
            } else if (nums[i] > nums[i - 1]) {
                q = i - 1;
                break;
            } else {
                return false;
            }
        }

        for (int i = q + 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                continue;
            }

            else {
                return false;
            }
        }

        return (p == 0 || q == 0) ? false : true;
    }
};