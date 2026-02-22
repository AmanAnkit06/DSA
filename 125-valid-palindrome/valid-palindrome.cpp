class Solution {
public:
    bool isPalindrome(string s) {
        /*
        // brute force approach----------
        string str = "";
        for (char ch : s) {
            if (iswalnum(ch)) {
                if (ch >= 'a' && ch <= 'z') {
                    str += ch;
                } else {
                    ch = ch - 'A' + 'a';
                    str += ch;
                }
            }
        }

        string temp = str;
        reverse(temp.begin(), temp.end());

        return (str == temp) ? true : false;
        */

        // Using two pointer approach-------------

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
};