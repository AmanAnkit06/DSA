class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int, greater<int>> freq;
        for (int num : nums)
            freq[num]++;

        int ans = 1;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            int last = it->first;

            int res = 1;

            if (last == 1) {
                ans = max(ans, freq[1]);
                break;
            }

            while (true) {
                int curr = sqrt(last);

                if (curr * curr != last)
                    break;

                if (freq.count(curr) && freq[curr] >= 2) {
                    res += 2;
                    last = curr;
                } else {
                    break;
                }

                if (curr == 1)
                    break;
            }

            ans = max(ans, res);
        }

        return (ans % 2 == 0) ? ans - 1 : ans;
    }
};