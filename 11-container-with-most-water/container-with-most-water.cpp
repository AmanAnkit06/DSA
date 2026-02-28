class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_Area = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            max_Area = max(max_Area, h * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_Area;
    }
};