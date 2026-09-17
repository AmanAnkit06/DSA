class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int answer = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int crrLength = right - left + 1;

                if (left > 0 && dp[left - 1] != INT_MAX) {
                    answer = min(answer, crrLength + dp[left - 1]);
                }

                dp[right] = crrLength;
            }

            if (right > 0) {
                dp[right] = min(dp[right], dp[right - 1]);
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};