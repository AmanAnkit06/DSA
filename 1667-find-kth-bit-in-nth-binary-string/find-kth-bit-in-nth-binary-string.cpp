class Solution {
public:
    string invert(string str) {
        string s = "";
        for (char ch : str) {
            if (ch == '0')
                s += '1';
            else
                s += '0';
        }

        return s;
    }
    string rev(string str) {
        string st = "";

        for (int i = str.size() - 1; i >= 0; i--) {
            st += str[i];
        }
        return st;
    }
    string helper(int n, vector<string>& dp) {

        if (n == 1) {
            return dp[1];
        }

        if (dp[n] != "") {
            return dp[n];
        }
        string prev = helper(n - 1, dp);
        return dp[n] = prev + "1" + rev(invert(prev));
    }

    char findKthBit(int n, int k) {
        // s1="0"
        //  s2="0"+"1"+reverse(invert(s1))=="011"
        // s3="011"+"1"+reverse("100")~"011"=="011"+"1"+"001"="0111001"
        if (n == 1)
            return '0';
        vector<string> dp(n + 1, "");

        dp[1] = "0";

        helper(n, dp);
        int i = 0;

        string temp = dp[n];

        return temp[k - 1];
    }
};