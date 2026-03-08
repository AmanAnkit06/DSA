class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high) {

        // Binary search on rotated sorted array
        // At every step we check which half of the array is sorted
        // If left half is sorted, check if target lies in that range
        // Otherwise search in the right half
        // If right half is sorted, check if target lies in that range
        // Otherwise search in the left half
        // Time Complexity - O(log n)
        // Space Complexity - O(1)
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if left part is sorted
            if (nums[mid] >= nums[low]) {
                ans = min(ans, nums[low]);
                low = mid + 1;

            }
            // cheeck if  Right part is sorted
            else if (nums[mid] <= nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
    int findMin(vector<int>& nums) {

        return binary_search(nums, 0, nums.size() - 1);
    }
};