class Solution {
public:
    void help(string& s) {
        char onesPlace = s[0];
        for (char& ch : s) {
            ch -= onesPlace - 'a';

            if (ch < 'a')
                ch += 26;
        }
    }
    long long countPairs(vector<string>& words) {
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> mp;
        mp.reserve(n);
        long long cnt = 0;
        for (string& s : words) {
            help(s);
            cnt += mp[s]++;
        }
        return cnt;
    }
};