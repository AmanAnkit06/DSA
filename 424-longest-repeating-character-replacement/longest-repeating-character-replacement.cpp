class Solution {
public:
    int helper(string s, int k) {

        // Here using two pointer we reduced time
        //   Time complexity- O(n +n)*26
        //  Space complexity- O(26);
        int ans = 0, l = 0, r = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        while (r < s.size()) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // here also not required to shrink more window that is previously
            // it is taking the size
            //  so you just shrink one and  ove forward--

            //  while ((r - l + 1) - maxFreq > k) {

            // so new time and space complexity will be changed and it is
            // otimized ---
            //   Time complexity- O(n)
            //  Space complexity- O(26);
            
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;

                // here we traverse the freqset that is not required because we
                // already reached the
                //  boundary of the change so no required to decrease the
                //  maxFreq

                /*maxFreq = 0;
                  for (int i = 0; i < 26; i++) {
                      maxFreq = max(maxFreq, freq[i]);
                  }*/

                l++;
            }

            ans = max(ans, (r - l + 1));
            r++;
        }

        return ans;
    }

    int characterReplacement(string s, int k) {

        // Brute force that is apply two for loop and counting each substring
        //  and checking the length by maintaining the freq--
        //  Time complexity- O(n^2)
        //  Space complexity- O(26);

        /*int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;
                if (changes <= k) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return ans; */

        return helper(s, k);
    }
};