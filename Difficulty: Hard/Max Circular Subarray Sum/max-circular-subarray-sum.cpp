class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int maxKadane = arr[0], currMax = arr[0];
        int minKadane = arr[0], currMin = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currMax = max(arr[i], currMax + arr[i]);
            maxKadane = max(maxKadane, currMax);

            currMin = min(arr[i], currMin + arr[i]);
            minKadane = min(minKadane, currMin);

            totalSum += arr[i];
        }
        totalSum += arr[0];

        
        if (maxKadane < 0)
            return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};
