class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int target) {

        // Binary search on rotated sorted array
        // At every step we check which half of the array is sorted
        // If left half is sorted, check if target lies in that range
        // Otherwise search in the right half
        // If right half is sorted, check if target lies in that range
        // Otherwise search in the left half
        // Time Complexity - O(log n)
        // Space Complexity - O(1)

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // Check if left part is sorted
            if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }
            // Right part is sorted
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};