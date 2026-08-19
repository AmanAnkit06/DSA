class Solution {
public:
    int helper(vector<int>& weights, int dayWeight) {
        int day = 1;
        int w = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (w + weights[i] > dayWeight) {
                day++;
                w = weights[i];
            } else {
                w += weights[i];
            }
        }

        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int h = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());

        while (l <= h) {
            int mid = (l + h) / 2;
            int d = helper(weights, mid);
            if (d <= days) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};