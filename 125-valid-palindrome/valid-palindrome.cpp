class Solution {
public:
    bool isPalindrome(string s) {
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
    }
};