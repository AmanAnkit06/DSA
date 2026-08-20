class Solution {
public:
    int helper(vector<int>& arr, int k, int mid) {
        int k1 = 0;
        int d = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {

                k1 = k1 + 1;
            }
            if (k1 == k) {

                d++;
                k1 = 0;
            } else if (arr[i] > mid) {
                k1 = 0;
            }
        }

        return d;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = high;
        while (low <= high) {

            int mid = (low + high) / 2;
            int m1 = helper(bloomDay, k, mid);

            if (m1 < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return (low > maxi) ? -1 : low;
    }
};