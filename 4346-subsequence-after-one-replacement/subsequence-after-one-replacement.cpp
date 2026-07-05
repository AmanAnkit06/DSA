/*class Solution {
public:
    int helper(string& s, string& t, vector<vector<vector<int>>>& dp, int n,
               int m, bool taken) {
        if (n == 0 || m == 0) {
            return 0;
        }
        if (dp[n][m][taken] != -1) {
            return dp[n][m][taken];
        }
        int ans = 0;
        if (s[n - 1] == t[m - 1]) {
            ans = 1 + helper(s, t, dp, n - 1, m - 1, taken);
        } else {
            ans = max(helper(s, t, dp, n - 1, m, taken),
                      helper(s, t, dp, n, m - 1, taken));
            if (!taken) {
                ans = max(ans, (1 + helper(s, t, dp, n - 1, m - 1, true)));
            }
        }
        return dp[n][m][taken] = ans;
    }
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n > m)
            return false;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));

        int sz = helper(s, t, dp, n, m, 0);
        return sz == n ? true : false;
    }
};*/

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> pref(n + 1, 1e9);
        pref[0] = -1;
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                pref[i + 1] = j;
                i++;
            }
            j++;
        }

        vector<int> suff(n + 1, -1e9);
        suff[n] = m;
        i = n - 1;
        j = m - 1;
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) {
                suff[i] = j;
                i--;
            }
            j--;
        }

        
        for(int k=0;k<n;k++){
            int leftbound=pref[k];
            int rightbound=suff[k+1];
            if(leftbound!=1e9 && rightbound!=1e9 && rightbound-leftbound>1){
                return true;
            }
        }

        return false;
    }
};