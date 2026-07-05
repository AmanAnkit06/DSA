class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int, int>> p;
        for (int i : nums) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            int sum = i;
            while (sum != 0) {
                int k = sum % 10;
                maxi = max(maxi, k);
                mini = min(mini, k);
                sum /= 10;
            }
            cout << maxi << " " << mini << endl;
            p.push_back({maxi - mini, i});
        }

        sort(p.rbegin(), p.rend());
        int ans = 0;
        int k = p[0].first;
        for (int i = 0; i < p.size(); i++) {
            if (k == p[i].first) {
                ans += p[i].second;
            }
        }

        return ans;
    }
};