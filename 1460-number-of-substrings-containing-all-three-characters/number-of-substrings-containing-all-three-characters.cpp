class Solution {
public:
    /* int cnt = 0;
     int count(string t) {
         set<char> st;
         for (char ch : t) {
             st.insert(ch);
         }
         return st.size() == 3 ? 1 : 0;
     }
     void helper(string s, int i, string& temp) {
         if (i == s.size()) {
             return;
         }
         temp += s[i];
         cnt += count(temp);
         helper(s, i + 1, temp);
         temp.pop_back();
         if (temp.empty())
             helper(s, i + 1, temp);
     }*/
    int numberOfSubstrings(string s) {

        /*
            string str = "";
            helper(s, 0, str);
            return cnt;
        */

        int i = 0;
        int j = 0;
        int n = s.size();
        int cnt = 0;
        map<char, int> mp;

        while (j < n) {
            mp[s[j]]++;
            if (mp.size() == 3) {

                while (i < j && mp.size() >= 3) {
                    mp[s[i]]--;
                    cnt += n - j;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return cnt;
    }
};