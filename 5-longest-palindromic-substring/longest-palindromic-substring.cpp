class Solution {
public:
    string longestPalindrome(string s) {

        string t = "#";
        for (char ch : s) {
            t += ch;
            t += "#";
        }
        int n = t.size();
        int l = 0;
        int r = -1;
        vector<int> p(n, 0);
        int maxLen = 0;
        int center = 0;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) {
                k++;
            }

            p[i] = k--;

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }
        int start = (center - maxLen + 1) / 2;
        return s.substr(start, maxLen - 1);
    }
};