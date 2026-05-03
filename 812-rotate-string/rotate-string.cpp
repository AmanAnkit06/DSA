class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        int n = s.size();
        while (i < n) {
            string str = s.substr(1, n - 1);

            str += s[0];
            s = str;
            i++;
            if (str == goal) {
                return true;
            }
        }
        return false;
    }
};