class Solution {
public:
    void helper(string word, set<string>& st, int i, string& temp) {
        if (i == word.size()) {
            return;
        }

        temp.push_back(word[i]);
        st.insert(temp);
        helper(word, st, i + 1, temp);
        temp.pop_back();

        if (temp.empty()) {
            helper(word, st, i + 1, temp);
        }
    }
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> st;
        string s = "";
        helper(word, st, 0, s);
        int cnt = 0;
        for (string str : st) {
            cout << str << endl;
        }
        for (string str : patterns) {
            if (st.find(str) != st.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};