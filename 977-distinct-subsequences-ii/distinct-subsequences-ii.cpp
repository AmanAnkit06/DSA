class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long > dp(n + 1, 0);
        map<char, int> mp;
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = (2 * dp[i - 1])%mod;

            char ch = s[i - 1];
            if (mp.count(ch)) {
                int j = mp[ch];
                dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
            }

            mp[ch] = i;
        }

        return (int)((dp[n] - 1+mod)%mod);
    }
};