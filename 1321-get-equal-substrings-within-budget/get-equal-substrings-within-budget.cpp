class Solution {
public:
    static int equalSubstring(string& s, string& t, int maxCost) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + abs(s[i] - t[i]);
        }
        for(auto x:sum)
        {
            cout<<x<<" ";
        }
        int l = 0, len = 0;
        for (int i = 0; i < n; i++) {
            int cost = sum[i + 1] - sum[l];
            while (cost > maxCost) {
                cost = sum[i + 1] - sum[++l];
                
            }
            len = max(len, i - l + 1);
        }
        return len;
    }
};
