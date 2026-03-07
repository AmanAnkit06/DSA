class Solution {
public:
    // Optimized approach using Sliding Window technique
    // We expand the window using right pointer and maintain frequency of
    // characters of t When all characters are matched, we try shrinking the
    // window from the left to get the minimum valid substring Time Complexity -
    // O(n) Space Complexity - O(128)

    string helper(string s, string t) {

        vector<int> freq(128, 0);
        for (char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            while (count == 0) {

                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }

    string minWindow(string s, string t) {

        // Brute force approach where we try every possible substring using two
        // loops
        // For every starting index we maintain a frequency map of characters of
        // t While expanding the substring we decrease the frequency and count
        // matched characters Once all characters of t are matched, we update
        // the minimum window length Time Complexity - O(n^2) Space Complexity -
        // O(26)

        /*   int ans = INT_MAX;
           string temp = "";
           int n = t.size();

           for (int i = 0; i < s.size(); i++) {
               unordered_map<char, int> mp;

               for (char c : t) {
                   mp[c]++;
               }

               int change = 0;

               for (int j = i; j < s.size(); j++) {
                   if (mp[s[j]] > 0) {
                       change++;
                   }

                   mp[s[j]]--;

                   if (change == n) {
                       int prev = ans;
                       ans = min(ans, j - i + 1);

                       if (prev != ans) {
                           temp = s.substr(i, j - i + 1);
                       }
                       break;
                   }
               }
           }

           if (ans == INT_MAX)
               return "";
           return temp; */

        return helper(s, t);
    }
};