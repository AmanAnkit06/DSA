class Solution {
public:
    bool isValid(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {

                return isValid(i, j - 1, s) || isValid(i + 1, j, s);
            }
            i++;
            j--;
        }
        return true;
    }
};